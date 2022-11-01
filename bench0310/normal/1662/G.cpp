#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
        v[i].push_back(p);
    }
    vector<int> sz(n+1,0);
    vector<int> depth(n+1,0);
    function<void(int,int)> dfs=[&](int a,int p)
    {
        depth[a]=depth[p]+1;
        sz[a]=1;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            sz[a]+=sz[to];
        }
    };
    dfs(1,0);
    function<int(int,int)> find_centroid=[&](int a,int p)->int
    {
        for(int to:v[a]) if(to!=p&&sz[to]>n/2) return find_centroid(to,a);
        return a;
    };
    int c=find_centroid(1,0);
    dfs(c,0);
    ll res=0;
    for(int i=1;i<=n;i++) res+=(depth[i]-1);
    const int N=1000000;
    bitset<N/2+1> b;
    b[0]=1;
    vector<int> cnt(n+1,0);
    for(int to:v[c]) cnt[sz[to]]++;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;cnt[i]>0;j*=2)
        {
            int m=min(cnt[i],j);
            cnt[i]-=m;
            b=(b|(b<<(m*i)));
        }
    }
    ll mx=0;
    for(int i=0;i<=N/2;i++) if(b[i]) mx=max(mx,ll(i)*(n-1-i));
    cout << res+mx+n << "\n";
    return 0;
}