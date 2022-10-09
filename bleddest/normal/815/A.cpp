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

const int N = 200;

int n, m;

int best = -1;
int bans = INF;

int a[N][N];
int sumx[N];
int sumy[N];


bool read() {
 	if(!(cin >> n >> m))
 		return false;
 	forn(i, n) forn(j, m)
 		cin >> a[i][j];
 	return true;
}

void solve() {
	for(int i = 0; i <= *max_element(a[0], a[0] + m); i++)
	{
		sumx[0] = i;
		forn(j, m)
			sumy[j] = a[0][j] - sumx[0];
		for(int j = 1; j < n; j++)
			sumx[j] = a[j][0] - sumy[0];
		bool ans = true;
		int cur = 0;
		forn(j, n)
		{
			ans &= (sumx[j] >= 0);
			cur += sumx[j]; 	
		}
		forn(j, m)
		{
		 	ans &= (sumy[j] >= 0);
		 	cur += sumy[j];
		}
		forn(j, n) forn(k, m) ans &= (sumx[j] + sumy[k] == a[j][k]);
		if (ans && cur < bans)
		{
			best = i;
			bans = cur;
		}
	}
	if (best == -1)
		puts("-1");
	else
	{
	 	printf("%d\n", bans);
	 	sumx[0] = best;
	 	forn(j, m)
			sumy[j] = a[0][j] - sumx[0];
		for(int j = 1; j < n; j++)
			sumx[j] = a[j][0] - sumy[0];
		forn(j, n) forn(k, sumx[j]) printf("row %d\n", j + 1);
		forn(j, m) forn(k, sumy[j]) printf("col %d\n", j + 1);	
	}
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