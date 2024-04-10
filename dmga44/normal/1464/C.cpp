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

    ll n,t;
    cin >> n >> t;
    vector<ll> f(26);
    ll base=0;
    string s;
    cin >> s;
    ll tot=0;
    for(int i=0;i<n-2;i++)
    {
        f[s[i]-'a']++;
        tot+=(1<<s[i]-'a');
    }
    base+=1<<(s[n-1]-'a');
    base-=1<<(s[n-2]-'a');
    ll dif=t-base;
    if(dif<0)
        dif=-dif;
    if((tot-dif)&1)
    {
        db("No")
        return 0;
    }
    else
        dif=(tot-dif)/2;

    for(int i=25;i>=0;i--)
    {
        if((ll)(f[i]*(ll)(1<<i))<=dif)
            dif-=(f[i]*(ll)(1<<i));
        else
            dif=(dif&((1<<i)-1));
    }
    if(dif==0)
        db("Yes")
    else
        db("No")

    return 0;
}