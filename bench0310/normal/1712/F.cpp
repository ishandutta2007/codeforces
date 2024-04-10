#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> v[N];
int leaf[N];
int deep[N];
int big[N];
const int Q=10;
int t;
int x[Q],k[Q];

void dfs(int a,int p,int d)
{
    deep[a]=d;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a,d+1);
        deep[a]=max(deep[a],deep[to]);
        if(deep[a]==deep[to]) big[a]=to;
    }
}

vector<int> go(int a,int p)
{
    vector<int> e;
    if(big[a]!=0) e=go(big[a],a);
    e.push_back(leaf[a]);
    int len=(int)e.size()-1;
    if(len-1>=0) e[len]=max(e[len],e[len-1]);
    for(int to:v[a])
    {
        if(to==p||to==big[a]) continue;
        vector<int> f=go(to,a);
        f.push_back(leaf[a]);
        int s=(int)f.size()-1;
        if(s-1>=0) f[s]=max(f[s],f[s-1]);
        for(int d=0;d<=s;d++)
        {
            for(int i=0;i<t;i++)
            {
                while(len-max(0,k[i]-d)>=0&&f[s-d]+e[len-max(0,k[i]-d)]+x[i]>=k[i]) k[i]++;
            }
        }
        for(int d=s;d>=0;d--)
        {
            e[len-d]=max(e[len-d],f[s-d]);
            if(len-d-1>=0) e[len-d]=max(e[len-d],e[len-d-1]);
        }
    }
    for(int i=0;i<t;i++) while(len-k[i]>=0&&leaf[a]+e[len-k[i]]+x[i]>=k[i]) k[i]++;
    return e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
        v[i].push_back(p);
    }
    queue<int> q;
    for(int i=1;i<=n;i++) leaf[i]=-1;
    auto add=[&](int a,int l)
    {
        if(leaf[a]==-1)
        {
            leaf[a]=l;
            q.push(a);
        }
    };
    for(int i=1;i<=n;i++) if(v[i].size()==1) add(i,0);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a]) add(to,leaf[a]+1);
    }
    dfs(1,0,1);
    cin >> t;
    for(int i=0;i<t;i++) cin >> x[i];
    go(1,0);
    for(int i=0;i<t;i++) cout << k[i]-1 << " \n"[i==t-1];
    return 0;
}