#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> depth(N,0);
vector<int> tin(N,0);
vector<int> tout(N,0);
int tcnt=1;
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> g[N];
vector<bool> bad(N,0);
int res=0;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    tin[a]=tcnt++;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
    tout[a]=tcnt-1;
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int dist(int a,int b)
{
    return (depth[a]+depth[b]-2*depth[lca(a,b)]);
}

bool sub(int a,int b)
{
    return (tin[a]<=tin[b]&&tin[b]<=tout[a]);
}

void solve(int a,int par=-1)
{
    int c=0;
    for(int to:g[a])
    {
        if(to==par) continue;
        solve(to,a);
        c+=bad[to];
    }
    if(bad[a]==1) res+=c;
    else
    {
        if(c>=2) res++;
        else if(c==1) bad[a]=1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int q;
    cin >> q;
    while(q--)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        for(int i=0;i<k;i++) cin >> a[i];
        sort(a.begin(),a.end(),[](int x,int y){return (tin[x]<tin[y]);});
        for(int x:a) bad[x]=1;
        for(int i=0;i<k-1;i++) a.push_back(lca(a[i],a[i+1]));
        sort(a.begin(),a.end(),[](int x,int y){return (tin[x]<tin[y]);});
        stack<int> s;
        s.push(a[0]);
        bool ok=1;
        for(int i=1;i<(int)a.size();i++)
        {
            if(a[i]==a[i-1]) continue;
            while(!sub(s.top(),a[i])) s.pop();
            g[s.top()].push_back(a[i]);
            g[a[i]].push_back(s.top());
            if(bad[a[i]]&&bad[s.top()]&&dist(a[i],s.top())==1) ok=0;
            s.push(a[i]);
        }
        res=0;
        solve(a[0]);
        if(!ok) res=-1;
        cout << res << "\n";
        for(int x:a) g[x].clear();
        for(int x:a) bad[x]=0;
    }
    return 0;
}