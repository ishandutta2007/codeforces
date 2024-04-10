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

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 400043;

int n, x, y;
string s;
char buf[N];

bool read() {
 	if(scanf("%d %d %d", &n, &x, &y) != 3)
 		return false;
 	scanf("%s", buf);
 	s = buf;
 	return true;
}

void solve() {
	int cnt = 0;
	forn(i, n)
	{
		if(s[i] == '0' && (i == 0 || s[i - 1] == '1'))
			cnt++;
	}
	if(cnt == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", y + li(cnt - 1) * 1ll * min(x, y));
	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	if(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}