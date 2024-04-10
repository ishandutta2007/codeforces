#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        string s2=s;
        int p=0;
        while(s2.size()<x)
        {
            int lim=s2.size();
            for(int i=0;i<s2[p]-'0'-1 && s2.size()<x;i++)
                for(int j=p+1;j<lim && s2.size()<x;j++)
                    s2.push_back(s2[j]);
            p++;
        }

//        db(s2)
        ll res=s.size();
        for(int i=0;i<x;i++)
            res=(res+(s2[i]-'0'-1)*(res-i-1+mod))%mod;
        db(res)
    }

    return 0;
}