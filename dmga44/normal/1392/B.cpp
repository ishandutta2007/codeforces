#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];

        ll pos=0;
        vector<int> last2(n);
        vector<int> last(n);
        while(pos<k)
        {
            int ma=-1e9;
            for(int i=0;i<n;i++)
            {
                last2[i]=last[i];
                last[i]=v[i];
                ma=max(ma,last[i]);
            }
            for(int i=0;i<n;i++)
                v[i]=ma-v[i];
            pos++;

            bool ok=1;
            for(int i=0;i<n;i++)
                ok&=(v[i]==last2[i]);

            if(ok)
            {
                ll x=k-pos;
                x-=(x&1);
                pos+=x;
            }
        }

        for(int i=0;i<n;i++)
            cout << v[i] << ' ';
        cout << '\n';
    }

    return 0;
}
/**
3
2 1
-199 192
5 19
5 -1 4 2 0
1 2
69
**/