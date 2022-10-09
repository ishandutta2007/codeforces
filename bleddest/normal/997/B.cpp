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

int n;
bool dp[50043][1043];

bool read() {
 	if(!(cin >> n))
 		return false;
 	return true;
}

void solve() {
	if(n <= 100)
	{
		dp[0][0] = true;
		forn(i, n)
			fore(j, i, i * 50 + 1)
				if(dp[j][i])
				{
					dp[j + 1][i + 1] = true;
					dp[j + 5][i + 1] = true;
					dp[j + 10][i + 1] = true;
					dp[j + 50][i + 1] = true;
				}
		int ans = 0;
		forn(i, 50043)
			if(dp[i][n])
				ans++;
		cout << ans << endl;
	}
	else
	{
		int k = n - 100;
		cout << 4653 + k * 1ll * 49 << endl;
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

	while(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}