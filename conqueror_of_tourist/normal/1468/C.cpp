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

// END UTIL


const int maxN = 500005;

int q;
map<pii,int> M, P;

void solve() {
	cin >> q;
	int m = 1;
	FOR(i, q) {
		int typ; cin >> typ;
		if (typ == 1) {
			int amt = ri();
			M[mp(i,-amt)] = P[mp(-amt,i)] = m++;
		} else if (typ == 2) {
			auto [j, v] = *M.begin();
			cout << v << " ";
			M.erase(j);
			P.erase(mp(j.second,j.first));
		} else if (typ == 3) {
			auto [j, v] = *P.begin();
			cout << v << " ";
			P.erase(j);
			M.erase(mp(j.second,j.first));
		}
	}
	cout << endl;
}