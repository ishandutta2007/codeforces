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

const int N = 10043;

li dp1[N];
li dp2[N];
li s[N];
li t[N];
li c;
int n;

void step(int x)
{
 	for(int i = 0; i <= n; i++) dp2[i] = INF64;
 	for(int i = 0; i < n; i++)
 	{
 		if (dp1[i] == INF64) 
 		{
 		  	break;
 		}
 		dp2[i] = min(dp2[i], dp1[i] + s[x] + c * i);
 		dp2[i + 1] = min(dp2[i + 1], dp1[i] + t[x]);	
 	} 	
 	
 	for(int i = 0; i <= n; i++)
 		dp1[i] = dp2[i];
}

bool read() {
 	if(!(cin >> n >> c))
 		return false;
 	forn(i, n) cin >> s[i];
 	forn(i, n) cin >> t[i];
 	return true;
}

void solve() {
	forn(i, N) dp1[i] = dp2[i] = INF64;
	dp1[0] = 0;
	forn(i, n) step(i);
	cout << *min_element(dp1, dp1 + n + 1) << endl;
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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