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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

ll a[MAXN];
ll dp[MAXN];
ll n,r1,r2,r3,d;

ll v(int i)
{
    return min(min(r2+r1,r1*(a[i]+2)),a[i]*r1+r3);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r1 >> r2 >> r3 >> d;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=1;i<n;i++)
        dp[i]=oo;

    ll mi=oo;
    ll sum=0;
    for(ll i=1;i<n;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+a[i-1]*r1+r3+d);
//        db(i)
        if(i>1)
        {
//            db(sum)
//            cout << mi+sum+v(i-1)+3*d*i << '\n';
            dp[i]=min(dp[i],mi+sum+v(i-1)+3*d*i);
        }
        mi=min(mi,-(i)*3*d+d-sum+dp[i-1]);
//        cout << -(i)*3*d+d-sum+dp[i-1] << '\n';
//        db("")
        sum+=v(i-1);
    }

//    for(int i=0;i<n;i++)
//        cout << i << ": " << dp[i] << '\n';
//    cout << '\n';

    ll res=oo;
    sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
            sum=min(min(r2+r1,r1*(a[i]+2))+2*d,a[i]*r1+r3);
        else
            sum+=2*d+v(i);
//        db(i)
//        cout << dp[i]+sum << '\n';
        res=min(res,dp[i]+sum);
        if(i==n-2)
        {
            res=min(res,dp[i]+2*d+v(i)+min(min(r2+r1,r1*(a[i+1]+2))+d,a[i+1]*r1+r3));
//            db(dp[i]+2*d+v(i)+min(min(r2+r1,r1*(a[i+1]+2))+d,a[i+1]*r1+r3))
        }
    }
    db(res)

    return 0;
}
/**
4 1 3 4 3
3 2 5 1
4 2 4 4 1
4 5 1 2
2 1 1 3 1
2 2
8 1 2 3 1
10 10 10 1 10 10 10 1
**/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
//#pragma GCC optimize("03")
//
//#include <bits/stdc++.h>
//#define db(x) cout << (x) << '\n';
//#define all(v) (v).begin(),(v).end()
//#define allr(v) (v).rbegin(),(v).rend()
//#define f first
//#define s second
//using namespace std;
//typedef long long ll;
//typedef double ld;
//typedef pair<ll,ll> pii;
//typedef pair<ld,ll> pdi;
//typedef pair<ld,ld> pdd;
//typedef pair<double,pii> pdp;
//typedef pair<string,ll> psi;
//typedef pair<ll,string> pls;
//typedef pair<string,string> pss;
//typedef pair<ll,pii> pip;
//typedef pair<pii,pii> ppp;
//typedef complex<ll> point;
//typedef pair<point,int> ppi;
//#define mod (ll)(998244353)
//#define eps (1e-9)
//#define oo (ll)(1e18)
//#define pi acos(-1)
//#define MAXN (ll)(1e6+5)
//
//ll a[MAXN];
//ll dp[MAXN];
//ll n,r1,r2,r3,d;
//
//ll v(int i)
//{
//    return min(min(r2+r1,r1*(a[i]+2)),a[i]*r1+r3);
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> n >> r1 >> r2 >> r3 >> d;
//    for(int i=0;i<n;i++)
//        cin >> a[i];
//
//    for(int i=1;i<n;i++)
//        dp[i]=oo;
//
//    for(int i=0;i<n-1;i++)
//    {
//        dp[i+1]=min(dp[i+1],dp[i]+a[i]*r1+r3+d);
//        if(i+2<n)
//        {
//            ll x0=v(i);
//            ll x1=v(i+1);
//            dp[i+2]=min(dp[i+2],dp[i]+x0+x1+4*d);
//        }
//    }
//
//    for(int i=0;i<n;i++)
//        cout << i << ": " << dp[i] << '\n';
//    cout << '\n';
//
//    ll res=oo;
//    ll sum=0;
//    for(int i=n-1;i>=0;i--)
//    {
//        if(i==n-1)
//            sum=min(min(r2+r1,r1*(a[i]+2))+2*d,a[i]*r1+r3);
//        else
//            sum+=2*d+v(i);
//        res=min(res,dp[i]+sum);
//    }
//    db(res)
//
//    return 0;
//}