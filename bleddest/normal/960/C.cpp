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

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 
const li INFF = INF * 42ll;

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

int x, d;

bool read() {
 	if(!(cin >> x >> d))
 		return false;
 	return true;
}

void solve() {
	vector<li> ans;
	int cur = 1;
	int cur_num = (1 << 30) - 1;
	int cnt = 30;
	while(x > 0)
	{
		if(x >= cur_num)
		{
			forn(i, cnt) ans.pb(cur * INFF);
			x -= cur_num;
			cur++;
		}
		else
		{
			cur_num >>= 1;
			cnt--;
		}
	}
	cout << sz(ans) << endl;
	for(auto x : ans) cout << x << " ";
	cout << endl;
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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