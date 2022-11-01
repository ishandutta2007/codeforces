#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=400005;
int n;
vector<int> v[N];
vector<int> sz(N,0);
vector<int> val(N,0);
vector<int> big(N,0);
vector<array<int,2>> mx(N,{0,0});
vector<bool> res(N,0);

void dfs(int a,int p=-1)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
        if(sz[to]>n/2) big[a]=to;
        val[a]=max(val[a],val[to]);
        if(val[to]>mx[a][0]) mx[a]={val[to],mx[a][0]};
        else if(val[to]>mx[a][1]) mx[a][1]=val[to];
    }
    if(sz[a]<=n/2) val[a]=max(val[a],sz[a]);
    if((n-sz[a])>n/2) big[a]=p;
}

void solve(int a,int p=-1,int x=0)
{
    if(big[a]==0) res[a]=1;
    else if(big[a]==p) res[a]=((n-sz[a]-x)<=n/2);
    else res[a]=((sz[big[a]]-val[big[a]])<=n/2);
    for(int to:v[a])
    {
        if(to==p) continue;
        int nxt=x;
        nxt=max(nxt,(val[to]!=mx[a][0]?mx[a][0]:mx[a][1]));
        if(p!=-1&&n-sz[a]<=n/2) nxt=max(nxt,n-sz[a]);
        solve(to,a,nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}