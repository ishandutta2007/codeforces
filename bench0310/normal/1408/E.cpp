#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> p(N,0);
vector<int> sz(N,0);

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

bool merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return 0;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<int> a(m+1,0);
    vector<int> b(n+1,0);
    for(int i=1;i<=n+m;i++) p[i]=i;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<array<int,3>> edges;
    for(int i=1;i<=m;i++)
    {
        int s;
        cin >> s;
        for(int j=1;j<=s;j++)
        {
            int x;
            cin >> x;
            edges.push_back({a[i]+b[x],n+i,x});
        }
    }
    sort(edges.begin(),edges.end(),greater<array<int,3>>());
    ll res=0;
    for(auto [c,x,y]:edges)
    {
        if(merge_sets(x,y)==0) res+=c;
    }
    cout << res << "\n";
    return 0;
}