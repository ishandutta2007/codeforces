#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<int128> sums(19);
vector<int128> p10(19);

int128 tot(ll x)
{
    vector<int> ds;
    ll xx=x;
    while(xx)
    {
        ds.push_back(xx%10);
        xx/=10;
    }

    reverse(all(ds));

    int len=ds.size();

    int128 ans=0;
    for(int i=1;i<len;i++)
        ans+=sums[i-1]*9+p10[i-1]*45;
    // cout << (ll)(ans) << '\n';
    int128 act=0;
    for(int i=0;i<len;i++)
    {
        for(int j=(i==0);j<ds[i]+(i==(len-1));j++)
            ans+=(act+j)*p10[len-i-1]+sums[len-i-1];
        act+=ds[i];
        // cout << (ll)(ans) << '\n';
    }
    // cout << "end\n";
    return ans;
}

ll sum(ll x)
{
    int ans=0;
    while(x)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sums[0]=0;
    p10[0]=1;
    for(int i=1;i<19;i++)
    {
        sums[i]=45*i*p10[i-1];
        p10[i]=p10[i-1]*10;
    }

    ll a;
    cin >> a;
    
    // cout << tot(11) << '\n';

    ll l=0,r=1e18;
    while(r-l>1)
    {
        ll m=(l+r)>>1;
        if(tot(m)>=(int128)(a))
            r=m;
        else
            l=m;
    }

    // cout << r << ' ' << (ll)tot(r) << '\n';

    l=1;
    int128 act=tot(r);
    while(1)
    {
        if(act==a)
        {
            // cout << (ll)tot(l-1) << ' ' << (ll)tot(r) << ' ' << (ll)tot(r) - (ll)tot(l-1) << '\n'; 
            cout << l << ' ' << r << '\n';
            return 0; 
        }
        while(act>a)
        {
            act-=sum(l);
            l++;
        }
        while(act<a)
        {
            r++;
            act+=sum(r);
        }
    }

    return 0;   
}