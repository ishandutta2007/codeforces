#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=100005;
int n;
vector<int> v[N];
vector<int> sz(N,0);
vector<ll> big;

void dfs(int a,int p=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
    }
    if(p!=0) big.push_back((ll)sz[a]*(n-sz[a]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        sort(big.begin(),big.end(),greater<ll>());
        for(int i=0;i<n-1;i++) big[i]%=mod;
        int m;
        cin >> m;
        vector<ll> p(m);
        for(int i=0;i<m;i++) cin >> p[i];
        sort(p.begin(),p.end(),greater<ll>());
        int idx=0;
        int one=max(1,m-(n-1)+1);
        ll x=1;
        for(int i=0;i<one;i++)
        {
            x=(x*p[i])%mod;
            idx++;
        }
        ll res=(x*big[0])%mod;
        for(int i=1;i<n-1;i++)
        {
            x=1;
            if(idx<m) x=p[idx++];
            res=(res+big[i]*x)%mod;
        }
        cout << res << "\n";
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            sz[i]=0;
        }
        big.clear();
    }
    return 0;
}