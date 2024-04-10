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
typedef pair<ld,pii> pdp;
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
const ll oo=(ll)(1e9);
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
        ll m;
        cin >> m;
        ll r[4];
        for(int i=0;i<4;i++)
            r[i]=0;
        r[0]=1;
        for(ll po=0;po<61;po++)
        {
            int pos=min(po,2ll)+1;
            ll c00=1,c01=1;
            ll c10=0,c11=0;
            if(pos==2)
            {
                c01=2;
                c10=1;
            }
            else if(pos==3)
            {
                c01=3;
                c10=3;
                c11=1;
            }
            ll c[4];
            c[0]=c00;
            c[1]=c01;
            c[2]=c10;
            c[3]=c11;
            ll a[4];
            for(int i=0;i<4;i++)
                a[i]=r[i];
            for(int i=0;i<4;i++)
                r[i]=0;
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    if(((bool)((i+j)&1))==((bool)(m&(1ll<<po))))
                        r[((i+j)&(6))>>1]=(r[((i+j)&(6))>>1]+a[i]*c[j])%mod;
        }
        db(r[0])
    }

    return 0;
}