#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;

// min-convex hull trick
// for max, invert m, b in add_line and result of query_min
template <typename T>
struct convex_hull_trick {
	vector<double> start;
	int n = 0;
	vector<T> M, B;

	double meet(T m1, T b1, T m2, T b2) {
		return double(b2-b1)/(m1-m2);
	}
	
	//add mx + b in order of DECREASING slope
	//currently does not handle same-slope
	void add_line(T m, T b) {
		if(n == 0) {
			start.push_back(-1e300);
		} else {
			double mt;
			while((mt = meet(M[n-1], B[n-1], m, b)) <= start[n-1]) {
				start.pop_back(), M.pop_back(), B.pop_back(), --n;
			}
			start.push_back(mt);
		}
		M.push_back(m), B.push_back(b), ++n;
	}

	// get min of mx+b over all (m, b) lines given
	T query_min(T x) {
		int lo = 0, hi = n;
		while(hi-lo-1) {
			int md = (lo+hi)/2;
			if(x >= start[md]) lo = md;
			else hi = md;
		}
		return M[lo]*x+B[lo];
	}
};

ll a[N];
ll b[N];
ll d[N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	ll a_sum = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a_sum += a[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
	}

	ll add = a_sum * b[n];

	for(int i = 1; i <= n; ++i) b[i] -= b[n];

	convex_hull_trick<ll> cht;
	d[1] = b[1];
	cht.add_line(b[1], d[1]);

	for(int i = 2; i <= n; ++i) {
		d[i] = cht.query_min(a[i]-1) + b[i];
		cht.add_line(b[i], d[i]);
	}

	cout << d[n] + add << "\n";
}