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
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

int dp[(1 << 20)];

int cnt[100043];

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif

	srand(time(NULL));

	int n, q;
	scanf("%d %d", &n, &q);
	forn(i, (1 << 20)) dp[i] = INF;
	dp[0] = 0;
	cnt[0] = 1;
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		if(dp[x] == INF)
		{
			forn(j, (1 << 20)) 
				if(dp[j] <= i) 
					dp[j ^ x] = min(dp[j ^ x], i + 1);
			cnt[i + 1] = cnt[i];
		}
		else
			cnt[i + 1] = (cnt[i] * 2ll) % MOD;
	}
	forn(i, q)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(dp[y] > x)
			printf("%d\n", 0);
		else
			printf("%d\n", cnt[x]);
	}
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << " ms\n";
	tt = clock();
#endif

	
	return 0;
}