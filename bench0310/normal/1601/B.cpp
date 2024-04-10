#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
int n;
vector<array<int,2>> v[5*N];
void add(int a,int b,int d){v[a].push_back({b,d});}
vector<int> ajump(N,0);
vector<int> bjump(N,0);
vector<int> bnode(5*N,0);

void build(int idx,int l,int r)
{
    if(l==r)
    {
        add(n+idx,l+bjump[l],0);
        bnode[n+idx]=l;
    }
    else
    {
        int m=(l+r)/2;
        add(n+idx,n+2*idx,0);
        add(n+idx,n+2*idx+1,0);
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
    }
}

void update(int idx,int l,int r,int ql,int qr,int a)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) add(a,n+idx,1);
    else
    {
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),a);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> ajump[i];
        if(ajump[i]==i) add(i,0,1);
        ajump[i]=min(ajump[i],i-1);
    }
    for(int i=1;i<=n;i++) cin >> bjump[i];
    build(1,1,n);
    for(int i=1;i<=n;i++) update(1,1,n,i-ajump[i],i,i);
    vector<int> d(5*n+1,-1);
    vector<int> p(5*n+1,-1);
    deque<int> q;
    q.push_back(n);
    d[n]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop_front();
        for(auto [to,c]:v[a])
        {
            if(d[to]==-1||d[a]+c<d[to])
            {
                d[to]=d[a]+c;
                p[to]=a;
                if(c==0) q.push_front(to);
                else q.push_back(to);
            }
        }
    }
    if(d[0]!=-1)
    {
        vector<int> res;
        int a=0;
        while(p[a]!=-1)
        {
            if(a==0||bnode[a]!=0) res.push_back(bnode[a]);
            a=p[a];
        }
        cout << d[0] << "\n";
        ranges::reverse(res);
        for(int b:res) cout << b << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}