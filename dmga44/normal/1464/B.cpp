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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll n=s.size();
    ll x,y;
    cin >> x >> y;
    vector<ll> c0(n+1);
    vector<ll> c1(n+1);
    vector<ll> cx(n+1);
    for(int i=0;i<n;i++)
    {
        c0[i+1]=c0[i];
        c1[i+1]=c1[i];
        cx[i+1]=cx[i];
        if(s[i]=='0')
            c0[i+1]++;
        if(s[i]=='1')
            c1[i+1]++;
        if(s[i]=='?')
            cx[i+1]++;
    }

    ll best=2e18;
    ll sum=0;
    ///all 1
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
            sum+=c1[i]*y;
        if(s[i]=='1')
            sum+=c0[i]*x;
        if(s[i]=='?')
            sum+=c0[i]*x+(c0[n]-c0[i])*y;
    }
    best=min(best,sum);

//    db(sum)
    ///1-0
    for(int i=0;i<n;i++)
        if(s[i]=='?')
        {
            sum-=c0[i]*x+(c0[n]-c0[i])*y;
//            db(sum)
            sum+=c1[i]*y+(c1[n]-c1[i])*x;
//            db(sum)
            sum+=(cx[n]-cx[i+1]-cx[i])*x;
            best=min(best,sum);
//            cout << "1 "<< i << ' ' << sum << '\n';
        }
    ///0-1
    for(int i=0;i<n;i++)
        if(s[i]=='?')
        {
            sum-=c1[i]*y+(c1[n]-c1[i])*x;
            sum+=c0[i]*x+(c0[n]-c0[i])*y;
            sum+=(cx[n]-cx[i+1]-cx[i])*y;
            best=min(best,sum);
//            cout << "0 "<< i << ' ' << sum << '\n';
        }
    db(best)

    return 0;
}