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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll dp[MAXN];
ll ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0]=1;
    ac[1]=1;
    for(int i=1;i<MAXN-1;i++)
    {
        ll sum=dp[i-1]+ac[i-1];
        sum=min(sum,oo);
        dp[i]=sum;
        ac[i+1]=ac[i]+dp[i];
        ac[i+1]=min(ac[i+1],oo);
    }

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        if(dp[n]<k)
        {
            db(-1)
            continue;
        }
        k--;
        ll pos=1;
        while(pos<=n)
        {
            int falta=n-pos+1;
            ll sz=0;
            if(dp[falta]==oo)
            {
                sz=1;
            }
            else
            {
                for(int po=(1<<17);po;po>>=1)
                    if(sz+po<=falta && ac[falta]-ac[falta-sz-po]<=k)
                        sz+=po;
                sz++;
            }
            k-=(ac[falta]-ac[falta-sz+1]);
            pos+=sz;
            for(int i=1;i<=sz;i++)
                cout << pos-i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
/**
1
6 5
**/