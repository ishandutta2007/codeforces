#include<bits/stdc++.h>

using namespace std;

#define sz(x)                   (int)((x).size())
#define all(x)                  (x).begin(), (x).end()
#define mem0(x)                 memset(x, 0, sizeof (x))
#define mem1(x)                 memset(x, -1, sizeof (x))
#define DECIMAL(n)              std::cout << std::fixed << std::setprecision(n);
#define rep(i,a,b)              for(int32_t i = (a); i < (b); ++i)
#define between(i,x,y)          ((i) >= (x) && (i) <= (y))
// #define clamp(i,x,y)            (((i) < (x)) ? (x) : ((y) < (i)) ? (y) : (i)); assert((x) <= (y));
#define sqr(a)                  ((a) * (a))
#define pii                     pair<int32_t, int32_t>
#define pll                     pair<long long, long long>
#define mp                      make_pair
#define fi                      first  
#define sc                      second
#define pb                      push_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define lbd                     lower_bound
#define ubd                     upper_bound
#define int                     long long
#define ll                      long long

template<typename T, typename U> static inline void remax(T &x, U y) {if (x < y) {x = y;}}
template<typename T, typename U> static inline void remin(T &x, U y) {if (y < x) {x = y;}}

static mt19937_64 gen(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

const long double PI = 3.14159265358979323846264338;
const double eps = 1e-12;
const int fftmod = 998244353;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int32_t N = 1e5 + 10;
const int32_t NN = 1e6 + 10;


int block = cbrtl(1.0 * N * N);

struct Query {
	int l, r, t, idx;
	pair<int, pii> ord;
	Query(int a, int b, int c, int d) {
		l = a, r = b, t = c, idx = d;
		int tblock  = t / block;
		int lblock = ((tblock) % 4 <= 1) ? -(l / block) : +(l / block);
		int rblock = ((lblock) & 1) ? -r : +r;
		ord = {tblock, {lblock, rblock}};
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}

int cnt[3 * N], Mex[5000];
int out[3 * N];
vector<pii> upd;
vector<Query> qry;
inline void dobbysolver(int testcase)
{
	int n, q;
	cin >> n >> q;
	int a[n];
	vector<int> com;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		com.pb(a[i]);
	}

	int ii = 0;				// pointer for queries
	int tt = -1;			// pointer for update queries
	for (int i = 0; i < q; ++i) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			qry.emplace_back(l, r, tt, ii++);
		} else {
			int p, x;
			cin >> p >> x;
			p--;
			upd.pb({p, x});
			com.pb(x);
			tt++;
		}
	}

	sort(all(com));
	com.resize(unique(com.begin(), com.end()) - com.begin());
	for (int i = 0; i < n; ++i) {
		a[i] = lbd(all(com), a[i]) - com.begin();
	}
	for (pii& p : upd) {
		p.sc = lbd(all(com), p.sc) - com.begin();
	}

	sort(all(qry));

	int l = 0, r = 0, t = -1;
	cnt[a[0]]++;
	Mex[1]++;
	for (Query Q : qry) {
		while (t < Q.t) {
			t++;
			int pos = upd[t].fi;
			int nval = upd[t].sc;
			upd[t].sc = a[pos];
			if (between(pos, l, r)) {
				Mex[cnt[a[pos]]]--;
				cnt[a[pos]]--;
				Mex[cnt[a[pos]]]++;
				Mex[cnt[nval]]--;
				cnt[nval]++;
				Mex[cnt[nval]]++;
			}
			a[pos] = nval;
		}
		while (t > Q.t) {
			int pos = upd[t].fi;
			int nval = upd[t].sc;
			upd[t].sc = a[pos];
			if (between(pos, l, r)) {
				Mex[cnt[a[pos]]]--;
				cnt[a[pos]]--;
				Mex[cnt[a[pos]]]++;
				Mex[cnt[nval]]--;
				cnt[nval]++;
				Mex[cnt[nval]]++;
			}
			a[pos] = nval;
			t--;
		}
		while (l > Q.l) {
			l--;
			Mex[cnt[a[l]]]--;
			cnt[a[l]]++;
			Mex[cnt[a[l]]]++;
		}
		while (r < Q.r) {
			r++;
			Mex[cnt[a[r]]]--;
			cnt[a[r]]++;
			Mex[cnt[a[r]]]++;
		}
		while (l < Q.l) {
			Mex[cnt[a[l]]]--;
			cnt[a[l]]--;
			Mex[cnt[a[l]]]++;
			l++;
		}
		while (r > Q.r) {
			Mex[cnt[a[r]]]--;
			cnt[a[r]]--;
			Mex[cnt[a[r]]]++;
			r--;
		}
		out[Q.idx] = 1;
		while (Mex[out[Q.idx]]) out[Q.idx]++;
	}
	for (int i = 0; i < ii; ++i)
		cout << out[i] << '\n';
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int TESTS = 1;
	//cin >> TESTS;
	for (int i = 1; i <= TESTS; ++i) {
		// cout << "Case #" << i << ": ";
		dobbysolver(i);
		if (i != TESTS)	cout << '\n';
	}
	return 0;
}