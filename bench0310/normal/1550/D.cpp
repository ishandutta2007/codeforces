#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,l,r;
        cin >> n >> l >> r;
        const ll mod=1000000007;
        auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
        auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
        vector<ll> f(n+1,1);
        vector<ll> inv(n+1,1);
        vector<ll> finv(n+1,1);
        for(int i=2;i<=n;i++)
        {
            f[i]=mul(f[i-1],i);
            inv[i]=mod-mul(mod/i,inv[mod%i]);
            finv[i]=mul(finv[i-1],inv[i]);
        }
        auto c=[&](int a,int b)->ll
        {
            if(a<b||b<0) return 0;
            return mul(f[a],mul(finv[b],finv[a-b]));
        };
        int pos=0;
        int neg=0;
        vector<int> bad(n+1,0);
        vector<array<int,3>> e; //t,i,neg|pos
        for(int i=1;i<=n;i++)
        {
            e.push_back({i-l+1,i,0});
            e.push_back({-i+r+1,i,1});
        }
        sort(e.begin(),e.end());
        ll now=1; //not yet processed
        int idx=0;
        vector<array<int,2>> opt;
        if(n&1) opt={{n/2,n-n/2},{n-n/2,n/2}};
        else opt={{n/2,n/2}};
        ll res=0;
        while(1)
        {
            ll nxt=e[idx][0];
            for(auto [one,two]:opt)
            {
                if(pos<=one&&neg<=two) res=add(res,mul(nxt-now,c(n-pos-neg,one-pos)));
            }
            while(e[idx][0]==nxt)
            {
                if((++bad[e[idx][1]])==2) goto done;
                if(e[idx][2]==0) pos++;
                else neg++;
                idx++;
            }
            now=nxt;
        }
        done:;
        cout << res << "\n";
    }
    return 0;
}