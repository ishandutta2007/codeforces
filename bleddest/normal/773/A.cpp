#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

li x, y, p, q;
li ans;

bool read () {
	if (scanf("%lld %lld %lld %lld", &x, &y, &p, &q) != 4)
		return false;
	return true;
}

bool check(li k) {
	ans = 0;
	li pp = p * k;
	li qq = q * k;
	li xx = x;
	li yy = y;
	li add1 = (pp - xx);
	if(add1 < 0)
		return false;
	xx += add1;
	yy += add1;
	ans += add1;
	li add2 = (qq - yy);
	if(add2 < 0)
		return false;
	yy += add2;
	ans += add2;
	return (xx == pp && yy == qq);
}

li gcd(li a, li b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	if(q == 1) {
		li xx = x;
		li yy = y;
		li g = gcd(xx, yy);
		xx /= g;
		yy /= g;
		if(xx != p || yy != q) {
			puts("-1");
			return;
		}
	}
	li l = 1, r = MOD;
	while(r - l > 1) {
		li mid = (l + r) >> 1;
		if(!check(mid))
			l = mid;
		else
			r = mid;
	}
	fore(i, l, r + 1) {
		if(check(i)) {
			printf("%lld\n", ans);
			return;
		}
	}
	puts("-1");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
	
	int tc;
	scanf("%d", &tc);
	
	while(tc--) {
		read();	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}