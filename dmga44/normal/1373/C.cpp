#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        vector<int> ac(n+1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')
                ac[i+1]=ac[i]+1;
            else
                ac[i+1]=ac[i]-1;
        }

        for(int i=0;i<n;i++)
            ac[i+1]=min(ac[i+1],ac[i]);

        ll mi=ac[n];
        ll res=0;
        for(int i=0;i<n;i++)
            res+=(ac[i]-mi+1);
        db(res)
    }

    return 0;
}
/**
3
--+-
---
++--+-
**/