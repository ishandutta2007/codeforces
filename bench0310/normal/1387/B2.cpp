#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
int n;
vector<int> v[N];
vector<int> sz(N,0);
ll dist=0;
vector<int> ord;

void dfs(int a,int p=-1)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
    }
    dist+=(2*min(sz[a],n-sz[a]));
}

int centroid(int a,int p=-1)
{
    for(int to:v[a])
    {
        if(to==p) continue;
        if(sz[to]>n/2) return centroid(to,a);
    }
    return a;
}

void gen(int a,int p=-1)
{
    ord.push_back(a);
    for(int to:v[a])
    {
        if(to==p) continue;
        gen(to,a);
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
    int c=centroid(1);
    gen(c);
    vector<int> res(n+1,0);
    for(int i=0;i<n;i++) res[ord[i]]=ord[(i+n/2)%n];
    cout << dist << "\n";
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}