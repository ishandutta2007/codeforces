#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005
#define mod ((ll)(1e9+7))

vector<ll> g[MAXN];
bool mk[MAXN];
int sz;

ll qp(ll b,ll e)
{
    if(!e)
        return 1ll;
    ll inter=qp(b,e>>1);
    inter=(inter*inter)%mod;
    if(e&1)
        inter=(inter*b)%mod;
    return inter;
}

void dfs(ll u)
{
    mk[u]=1;
    sz++;
    for(auto y : g[u])
        if(!mk[y])
            dfs(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin >> n >> k;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,x;
        cin >> u >> v >> x;
        u--,v--;
        if(!x)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    ll res=qp(n,k);
    for(ll i=0;i<n;i++)
        if(!mk[i])
        {
            dfs(i);
            res=(res-qp(sz,k)+mod)%mod;
            sz=0;
        }
    db(res)

    return 0;
}