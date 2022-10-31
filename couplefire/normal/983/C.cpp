#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
#include <cassert>
 
#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]
#define next next239
#define prev prev239
#define ba back()
#define last(x) x[sz(x) - 1]
#define deb(x) cout << #x << " = " << (x) << endl
#define deba(x) do { cout << #x << " (size: " << sz(x) << ") = " << \
	"{"; for (auto o : x) cout << o << ","; cout << "}" << endl;} while (0)
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double LD;
typedef double D;
 
template<class T> T abs(T x) { return x > 0 ? x : -x;}
 
template<class T> T toString(T x) {
	ostringstream sout;
	sout << x;
	return sout.str();
}
 
int nint() {
	int x;
	scanf("%d", &x);
	re x;
}
 
const ll mod = 1000000000 + 7;
 
int m;
int n;
ll ans;
 
int a[2050], b[2050];
 
int table[2050][1050];
 
vi split(int x) {
	vi ans;
	rep(i, 3) {
		if (x % 10)
			ans.pb(x % 10);
		x /= 10;
	}
	re ans;
}
 
inline int merge(vi &v, int x) {
	int ans = 0;
	rep(i, 3) {
		ans *= 10;
		if (i < sz(v) && v[i] != x)
			ans += v[i];
	}
	re ans;
}
 
inline int get1(int l, int r, int x) {
	re min(abs(x - l), abs(x - r)) + r - l;
}
 
inline int get2(int l, int r, int x1, int x2) {
	re min(abs(x1 - l) + abs(x2 - r), abs(x1 - r) + abs(x2 - l)) + r - l;
}
 
int getans(int p, int cur) {
	int &ans = table[p][cur];
	if (ans != -1)
		re ans;
 
	int pos = a[p];
	vi v = split(cur);
	v.pb(b[p]);
	sort(all(v));
 
	if (p == n - 1) {
		ans = get1(v[0], v.back(), pos);
		re ans;
	}
 
	ans = mod;
	int ne = a[p + 1];
 
	if (sz(v) < 4)
		ans = min(ans, getans(p + 1, merge(v, ne)) + abs(ne - pos));
 
	rep(i, sz(v)) {
		if (i && (v[i] == v[i - 1]))
			continue;
 
		for (int j = i; j < sz(v); j++) {
			if (j < sz(v) - 1 && v[j] == v[j + 1])
				continue;
 
			int tmp = get2(v[i], v[j], pos, ne);
 
			vi tv;
			rep(k, sz(v)) {
				if (k < i || k > j)
					tv.pb(v[k]);
			}
 
			ans = min(ans, tmp + getans(p + 1, merge(tv, ne)));
		}
	}
 
	re ans;
}
 
int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand((int)time(0));
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
 
	cin >> n;
	rep(i, n)
		cin >> a[i] >> b[i];
 
	fill(table, -1);
	cout << getans(0, 0) + a[0] - 1 + 2 * n;
}