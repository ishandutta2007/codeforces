#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=3002;
vector<array<int,2>> v[N];
vector<int> e;
vector<int> c;
vector<int> p;

void add_one(int a,int b,int cap)
{
    int id=e.size();
    v[a].push_back({b,id});
    e.push_back(a);
    c.push_back(cap);
}

void add(int a,int b,int cap)
{
    add_one(a,b,cap);
    add_one(b,a,0);
}

bool go(int s,int t)
{
    p.assign(N,-1);
    p[s]=-2;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto [to,id]:v[a])
        {
            if(p[to]==-1&&c[id]>0)
            {
                p[to]=id;
                q.push(to);
            }
        }
    }
    return (p[t]!=-1);
}

int max_flow(int s,int t)
{
    int mx=0;
    while(go(s,t))
    {
        int a=t;
        int f=(1<<30);
        while(a!=s)
        {
            int id=p[a];
            f=min(f,c[id]);
            a=e[id];
        }
        a=t;
        while(a!=s)
        {
            int id=p[a];
            c[id]-=f;
            c[id^1]+=f;
            a=e[id];
        }
        mx+=f;
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b(n+1,0);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        b[i]=-b[i];
        if(b[i]<0) res+=b[i];
    }
    vector<int> prv(101,0);
    int s=0,t=n+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            if((a[i]%j)==0&&prv[j]!=0) add(i,prv[j],(1<<30));
        }
        prv[a[i]]=i;
        if(b[i]>0) add(i,t,b[i]);
        if(b[i]<0) add(s,i,-b[i]);
    }
    cout << -(res+max_flow(s,t)) << "\n";
    return 0;
}