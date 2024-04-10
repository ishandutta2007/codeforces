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
// typedef __int128_t int128;
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
#define MAXN (ll)(5e5+5)

template<typename T>
struct convex_hull_trick
{
    using point = std::complex<T>;
    using hull = std::vector<point>;

	void insert(const point &p)
	{
		hull lu(1, p), uh(1, p);
		for (std::size_t i = 0; i < lower_hull.size(); ++i)
			if (lower_hull[i].empty())
			{
				lu.swap(lower_hull[i]);
				uh.swap(upper_hull[i]);
				break;
			}
			else
			{
				lu = merge(lu, lower_hull[i], [](T val) { return val <= 0; });
				uh = merge(uh, upper_hull[i], [](T val) { return val >= 0; });
				lower_hull[i].clear();
				upper_hull[i].clear();
			}
		if (!lu.empty())
		{
			lower_hull.emplace_back(lu);
			upper_hull.emplace_back(uh);
		}
	}

	point extreme(const point &p) const
	{
		const auto &h = p.imag() > 0 ? upper_hull : lower_hull;
		point best;
		bool found = false;
		for (const hull &_h : h)
		{
			if (_h.empty()) continue;
			std::size_t lo = 0, hi = _h.size() - 1, mid;
			while (lo < hi)
			{
				mid = (lo + hi) / 2;
				point q = _h[mid] - _h[mid + 1];
				long double x = (long double) real(p) * real(q) + (long double) imag(p) * imag(q);
				int sign = x < -1e-10 ? -1 : x > 1e-10 ? 1 : 0;
				if (sign <= 0) lo = mid + 1;
				else hi = mid;
			}
			if (!found || dot(best, p) <= dot(_h[lo], p)) best = _h[lo];
			found = true;
		}
		assert(found);
		return best;
	}

	static T cross(const point &a, const point &b) { return std::imag(std::conj(a) * b); }
    static T dot(const point &a, const point &b) { return std::real(std::conj(a) * b); }

    void swap(convex_hull_trick &other)
    {
    	lower_hull.swap(other.lower_hull);
    	upper_hull.swap(other.upper_hull);
    }

private:
    std::vector<hull> lower_hull, upper_hull;

    template<typename F>
    static hull merge(const hull &a, const hull &b, const F &cond)
    {
        auto comp = [](const point &p, const point &q)
        {
            return p.real() < q.real() || (p.real() == q.real() && p.imag() < q.imag());
        };
        hull h;
        auto sign = [](long double x) { return x < -1e-10 ? -1 : x > 1e-10 ? 1 : 0 ;};
		auto add_point = [&](const point &p)
		{
			while (h.size() >= 2)
			{
				point a = h.end()[-1] - h.end()[-2], b = p - h.end()[-2];
				long double x = (long double) real(a) * imag(b) - (long double) imag(a) * real(b);
				if (!cond(sign(x))) break;
                h.pop_back();
			}
			h.emplace_back(p);
		};
		for (std::size_t i = 0, j = 0; i < a.size() || j < b.size();)
			add_point(i == a.size() || (j != b.size() && comp(b[j], a[i])) ? b[j++] : a[i++]);
		return h;
    }

    static int comp(T p, T q, T a, T b)
	{
		if (!p && !a) return 0;
		if (p < 0 && a >= 0) return -1;
		if (p >= 0 && a < 0) return 1;
		if (a <= 0 && p <= 0) return -comp(-p, q, -a, b);
		T v1 = p / q, v2 = a / b;
		if (v1 > v2) return 1;
		if (v1 < v2) return -1;
		p = p % q;
		a = a % b;
		if (!a && !p) return 0;
		if (!a) return 1;
		if (!p) return -1;
		return -comp(q, p, b, a);
	}
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> ac;
    vector<int> xs(n);
    for(int i=0;i<n;i++)
        cin >> xs[i];

    ll act=0;
    ll ans=0;
    ac.push_back(0);
    convex_hull_trick<ll> cht;
    cht.insert(point(0,0));
    for(int i=0;i<n;i++)
    {
        ac.push_back(ac.back()+xs[n-i-1]);
        act+=ac.back();

        cht.insert(point(-(act+ac.back()*(n-i-1)),ac.back()));
        ans=max(ans,act+cht.dot(cht.extreme(point(1,n-i-1)),point(1,n-i-1)));
    }
    cout << ans << '\n';

    return 0;   
}