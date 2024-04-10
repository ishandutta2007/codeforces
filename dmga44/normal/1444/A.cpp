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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll mul(ll a, ll b, ll M)
{
	ll q = (long double) a * (long double) b / (long double) M;
	ll r = a * b - q * M;
	return (r + 5 * M) % M;
}

ll pow(ll a, ll b, ll M)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = mul(x, a, M);
		a = mul(a, a, M);
	}
	return x;
}

bool witness(ll a, ll s, ll d, ll n)
{
	ll x = pow(a, d, n);
	if (x == 1 || x == n - 1)
		return 0;
	for (int i = 0; i < s - 1; i++)
	{
		x = mul(x, x, n);
		if (x == 1)
			return 1;
		if (x == n - 1)
			return 0;
	}
	return 1;
}

bool miller_rabin(ll n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	ll d = n - 1, s = 0;
	while (d % 2 == 0)
		++s, d /= 2;
	vector<ll> test = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (ll p : test)
		if (p >= n) break;
		else if (witness(p, s, d, n))
			return 0;
	return 1;
}

ll pollard_rho(ll n)
{
	if (!(n & 1))
		return 2;
	while (1)
	{
		ll x = (ll) rand() % n, y = x;
		ll c = rand() % n;
		if (c == 0 || c == 2) c = 1;
		for (int i = 1, k = 2;; i++)
		{
			x = mul(x, x, n);
			if (x >= c) x -= c;
			else x += n - c;
			if (x == n) x = 0;
			if (x == 0) x = n - 1;
			else x--;
			ll d = __gcd(x > y ? x - y : y - x, n);
			if (d == n)
				break;
			if (d != 1) return d;
			if (i == k)
			{
				y = x;
				k <<= 1;
			}
		}
	}
	return 0;
}

map<ll,ll> decomp(ll x)
{
    map<ll,ll> res;
    if(x==1)
        return res;
    if(miller_rabin(x))
    {
        res[x]=1;
        return res;
    }

    ll d=pollard_rho(x);
    map<ll,ll> m1=decomp(d);
    map<ll,ll> m2=decomp(x/d);
    for(auto y : m2)
        m1[y.f]+=y.s;
    return m1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll xi,qi;
        cin >> xi >> qi;
        if(xi%qi)
        {
            db(xi)
            continue;
        }
        map<ll,ll> dec=decomp(qi);
        vector<ll> divs;
        divs.push_back(1);
        vector<ll> aux;
        ll res=xi;
        for(auto y : dec)
        {
            ll mul=y.f;
            int e=0;
            ll xx=xi;
            while(xx%mul==0)
            {
                e++;
                xx/=mul;
            }
            res=min(res,pow(mul,e-y.s+1,oo));
        }

        db(xi/res)
    }

    return 0;
}