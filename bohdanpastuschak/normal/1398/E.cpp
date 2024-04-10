#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, LL> D;
const int N = 1 << 18;

void add(D* F, int pos, int val, bool was){
	for(; pos < N; pos |= pos + 1){
		if (was){
			F[pos].X++;
			F[pos].Y += val;
		}else{
			F[pos].X--;
			F[pos].Y -= val;
		}
	}
}

D query(D* F, int r){
	D res(0, 0);
	for(; r >= 0; r = (r & (r + 1)) - 1){
		res.X += F[r].X;
		res.Y += F[r].Y;
	}
	
	return res;
}

D query(D* F, int l, int r){
	assert(l <= r);
	auto R = query(F, r);
	auto L = query(F, l - 1);
	return {R.X - L.X, R.Y - L.Y};
}

LL sum_kth(D* F, int k){
	assert(query(F, N - 1).X >= k);
	int l = 0, r = N, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		auto tut = query(F, m, N - 1);
		if (tut.X >= k) l = m;
		else r = m;
	}

	return query(F, l, N - 1).Y;
}

D F0[N], F1[N], F[N];	

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<PII> a(n);
	vector<int> all = {0};
	
	FOR(i, 0, n){
		cin >> a[i].X >> a[i].Y;
		if (a[i].Y > 0) all.PB(a[i].Y);
	}

	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	FOR(i, 0, n){
		if (a[i].Y > 0) a[i].Y = lower_bound(ALL(all), a[i].Y) - all.begin();
		else a[i].Y = -(lower_bound(ALL(all), -a[i].Y) - all.begin());
	}

	vector<LL> ans(n, 0);
	vector<int> cnt0(n, 0), cnt1(n, 0);
	LL sum = 0, C1 = 0, C0 = 0;
	FOR(i, 0, n){
		if (a[i].Y > 0) sum += all[a[i].Y];
		else sum -= all[-a[i].Y];
		ans[i] = sum;
		if (a[i].X == 1){
			if (a[i].Y > 0) C1++;
			else C1--;
		}else{
			if (a[i].Y > 0) C0++;
			else C0--;
		}
		
		cnt1[i] = C1;
		cnt0[i] = C0;
	}

	FOR(i, 0, n){
		if (a[i].X == 0){
			if (a[i].Y > 0){
				add(F0, a[i].Y, all[a[i].Y], true);
				add(F, a[i].Y, all[a[i].Y], true);
			}else{
				add(F0, -a[i].Y, all[-a[i].Y], false);
				add(F, -a[i].Y, all[-a[i].Y], false);
			}
		}else{
			if (a[i].Y > 0){
				add(F1, a[i].Y, all[a[i].Y], true);
				add(F, a[i].Y, all[a[i].Y], true);
			}else{
				add(F1, -a[i].Y, all[-a[i].Y], false);
				add(F, -a[i].Y, all[-a[i].Y], false);
			}
		}

		if (cnt0[i] == 0){
			ans[i] += sum_kth(F1, cnt1[i] - 1);
		}else if (cnt1[i] > 0){
			LL val1 = sum_kth(F1, cnt1[i] - 1);
			LL val2 = sum_kth(F, cnt1[i]);
			if (sum_kth(F1, cnt1[i]) == val2){
				val2 = sum_kth(F, cnt1[i] + 1) - (val2 - val1);				
			}

			ans[i] += max(val1, val2);
		}
	}

	FOR(i, 0, n) cout << ans[i] << '\n';
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}