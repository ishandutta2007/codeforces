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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

// END UTIL

const int maxN = 5005;

string s;
#define P Point<int>

map<char, P> D = {
	{'L', {-1, 0}},
	{'R', {1, 0}},
	{'U', {0, 1}},
	{'D', {0, -1}}
};

void solve() {
	TIMES(ri()) {
		cin >> s;
		int n = s.size();
		P c;
		int out[2] = {0, 0};
		FOR(i, n) {
			c = c + D[s[i]];
			//DEBUG(c);
			P obs = c;
			P e;
			FOR(j, n) {
				P x = e + D[s[j]];
				if (!(x == obs)) e = x;
				//DEBUG(e);
			}
			if (e == P(0,0)) {
				out[0] = obs.x, out[1] = obs.y;
				break;
			}
		}
		cout << out[0] << " " << out[1] << "\n";
	}
}