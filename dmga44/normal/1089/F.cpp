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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

vector<pii> dp[MAXN][MAXN][6];
pii dp0[MAXN][MAXN][6];


ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
		return x = 1, y = 0, a;
	ll r = gcd(b, a % b, y, x);
	y -= a / b * x;
	return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> divs;
    for(int i=2;i<32000;i++)
        if(n%i==0)
        {
            divs.push_back(i);
            if(n!=i*i)
                divs.push_back(n/i);
        }

//    for(auto v : divs)
//        db(v)

    sort(all(divs));
    if(divs.size() && divs.back()==n)
        divs.pop_back();
    if(divs.size() && divs[0]==1)
    {
        reverse(all(divs));
        divs.pop_back();
        reverse(all(divs));
    }

    if(!divs.size())
    {
        db("NO")
        return 0;
    }

    vector<ll> primes;
    primes.push_back(divs[0]);
    for(int i=1;i<divs.size();i++)
        if(__gcd(divs[0],divs[i])==1 && primes.size()==1)
            primes.push_back(divs[i]);

    if(primes.size()==1)
    {
        db("NO")
        return 0;
    }

    ll c1,c2;
    ll _=gcd(primes[0],primes[1],c1,c2);
//    cout << primes[0] << ' ' << primes[1] << ' ' << c1 << ' ' << c2 << '\n';
    if(c1>0)
    {
        c1*=-1;
        c2*=-1;
        c1+=n/primes[0];
    }
    else
    {
        c1*=-1;
        c2*=-1;
        c2+=n/primes[1];
    }

    if(c1<0)
    {
        ll x=abs(c1)+primes[1]-(abs(c1)%primes[1]);
        ll dif=x/primes[1];
        c1+=dif*primes[1];
        c2-=dif*primes[0];
    }
    if(c2<0)
    {
        ll x=abs(c2)+primes[0]-(abs(c2)%primes[0]);
        ll dif=x/primes[0];
        c1-=dif*primes[1];
        c2+=dif*primes[0];
    }

    db("YES")
    db(2)
    cout << c1 << ' ' << n/primes[0] << '\n';
    cout << c2 << ' ' << n/primes[1] << '\n';

    return 0;
}