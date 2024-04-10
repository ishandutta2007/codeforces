#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll k;
        cin >> k;
        vector<ll> kk;
        kk.push_back(2);
        while(kk.back()<1e18)
            kk.push_back(kk.back()*2+2);
        if(k&1)
        {
            db(-1)
            continue;
        }
        int pos=kk.size()-1;
        vector<int> res;
        while(k)
        {
            while(k>=kk[pos])
            {
                res.push_back(1);
                for(int i=0;i<pos;i++)
                    res.push_back(0);
                k-=kk[pos];
            }
            pos--;
        }
        db(res.size())
        for(int i=0;i<res.size();i++)
            cout << res[i] << " \n"[i==res.size()-1];
    }

    return 0;
}