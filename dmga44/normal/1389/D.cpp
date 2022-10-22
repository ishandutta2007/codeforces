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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

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
        ll l1,r1;
        cin >> l1 >> r1;
        ll l2,r2;
        cin >> l2 >> r2;
        if(l1>l2)
        {
            swap(l1,l2);
            swap(r1,r2);
        }

        ll mid=max(0ll,l2-r1);
        ll inter=max(0ll,min(r1,r2)-l2);
        ll add=max(r2,r1)-l1-inter;
        if(inter*n>=k)
        {
            db(0)
            continue;
        }
        ll faltan=k-inter*n;
        if(faltan<=add)
        {
            db(mid+faltan)
            continue;
        }
        ll res=oo;
        for(ll i=1;i<=n;i++)
        {
            ll ops=(mid+add)*i;
            ll f=faltan-(add*i);
            if(f<0)
                continue;
            res=min(res,(ops+2*f));
            if(f<=add && i<n)
                res=min(res,(ops+mid+f));
        }
        db(res)
    }

    return 0;
}
/**
3
3 5
1 2
3 4
2 1000000000
1 1
999999999 999999999
10 3
5 10
7 8
**/