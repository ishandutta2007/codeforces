// optimization flags
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
// including std
#include <bits/stdc++.h>
using namespace std;
// use solve instead of main for easy fast input
void solve();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<setprecision(99);
	solve();
}
// generic printing of iterators
template<
	typename T_container, // container type
	typename T = typename enable_if<!is_same<T_container,string>::value, typename T_container::value_type>::type
> ostream& operator<<(ostream& os,const T_container& v){
	os << '{';
	string sep;
	for (const T& x: v) os<< sep << x, sep = ", ";
	return os << '}';
}
// python-ish read and print functions
template<typename T>
T read(){
	T x;
	cin >> x;
	return x;
}
template<typename T>
void read(T& x) {
	cin >> x;
}
template<typename T>
void print(const T& x) {
	cout << x<< "\n";
}
// macro/template hackery to get quick debug info
template<typename L> void DEBUG_(const char* str, L& last) { cout << str << " = " << last << endl; }
template<typename H, typename ...T> void DEBUG_(const char* str, H& val, T&... tail) {
	const char* comma = strchr(str, ',');
	cout << regex_replace(string(str, comma), regex("^ +| +$|( ) +"), "$1") << " = " << val << ", ";
	DEBUG_(comma+1, tail...);
}
#define DEBUG(...) DEBUG_(#__VA_ARGS__, __VA_ARGS__)
// macro hackery to generate new names
#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define FRESHVAR() CONCAT(__FRESHVAR__, __COUNTER__)
// use 64-bit integers by default
#define int int_fast64_t
#define db double
// iterator utility defines
#define AR array
#define IT(x) (x).begin(),(x).end()
#define sz size
// loop utility defines
#define TIMES_(i,n) for (int i = (n); i > 0; i--)
#define TIMES(n) TIMES_(FRESHVAR(), n)
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FORS(i,s,n) for (int i = (s); i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)
#define FORB(i,n)for (int i = (n) - 1; i >= 0; i--)
// common function defines
#define pb push_back
#define vi vector<int>
#define mp make_pair
#define ri read<int>
#define pii pair<int,int>

const string NOYES[2] = {"NO","YES"};
const string NoYes[2] = {"No","Yes"};
const int INF = numeric_limits<int>::max() / 10;

// UTILITY PASTE

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
// END UTIL

#define edge AR<int,3>

const int maxN = 200005;
int n, m, k;
edge E[maxN];

void solve() {
	TIMES(ri()) {
		cin >> n >> m >> k;
		FOR(i, m) {
			int x, y, s; cin >> x >> y >> s;
			x--; y--;
			E[i] = {x, y, s};
		}

		UF ts(n);
		vector<edge> mst;
		priority_queue<pair<int, int>> pq;
		FOR(i, m) pq.push(mp(-E[i][2], i));
		while (!pq.empty()) {
			auto [_, c] = pq.top(); pq.pop();
			if (ts.join(E[c][0], E[c][1])) mst.pb(E[c]);
		}

		int bad = 0;
		for (edge e : mst) if (e[2] > k) bad += e[2] - k;
		if (bad) {
			cout << bad << "\n";
		} else {
			int best = INF;
			FOR(i, m) best = min(best, abs(k - E[i][2]));
			cout << best << "\n";
		}
	}
}