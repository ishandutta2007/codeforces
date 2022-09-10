#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void build(int n, vector<vector<LL>>& a){
	a[n - 1][n - 1] = 64;
	RFOR(i, n - 1, 0) a[i][n - 1] = 2 * a[i + 1][n - 1];
	RFOR(i, n - 1, 1) a[0][i] = 2 * a[0][i + 1];

	vector<vector<LL>>f(n, vector<LL>(n));
	FOR(i, 0, n) FOR(j, 0, n) f[i][j] = a[i][j] / 32;
	
	FOR(i, 1, n) FOR(j, 0, n - 1){
		f[i][j] = f[i - 1][j + 1];
		a[i][j] = a[i - 1][j + 1] - f[i - 1][j + 1];
	}

	a[n - 1][n - 1] = 0;	
}


void check(int n, const vector<vector<LL>>& a){
	map<LL, vector<PII>> S;
	FOR(it, 0, 10000){
		int x = 0, y = 0;
		LL curr = 0;
		vector<PII> V;
		while(x != n - 1 || y != n - 1){
			if (x == n - 1) y++;
			else if (y == n - 1) x++;
			else{
				if (rng() & 1) x++;
				else y++;
			}

			V.PB({x, y});
			curr += a[x][y];
		}
	
		if (S.count(curr)){
			assert(S[curr] == V);
		}else{
			S[curr] = V;
		}			
	}	
}

vector<PII> solve(int n, LL k, const vector<vector<LL>>& a){
	vector<vector<LL>> dp(n, vector<LL>(n, 0));
	auto dp1 = dp;
	RFOR(i, n, 0) RFOR(j, n, 0){
		if (i + 1 == n && j + 1 == n) continue;
		if (i + 1 == n) dp1[i][j] = dp[i][j] = a[i][j] + dp[i][j + 1];
		else if (j + 1 == n) dp1[i][j] = dp[i][j] = a[i][j] + dp[i + 1][j];
		else {
			dp[i][j] = a[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
			dp1[i][j] = a[i][j] + max(dp1[i][j + 1], dp1[i + 1][j]);
		}
	}

	vector<PII> path;
	PII curr = {0, 0};
	while(curr != MP(n - 1, n - 1)){
		path.PB(curr);
		bool canL = curr.Y + 1 < n && k >= dp[curr.X][curr.Y + 1] && k <= dp1[curr.X][curr.Y + 1];
		bool canU = curr.X + 1 < n && k >= dp[curr.X + 1][curr.Y] && k <= dp1[curr.X + 1][curr.Y];

		if (canL) curr.Y++;
		if (canU) curr.X++;
		assert(canU ^ canL);
		k -= a[curr.X][curr.Y];		
	}

	path.PB({n - 1, n - 1});
	return path;
}

int main()
{
	int n; cin >> n;
	vector<vector<LL>> a(n, vector<LL>(n, 0));
	build(n, a);	
	FOR(i, 0, n){
		FOR(j, 0, n) cout << a[i][j] << ' ';
		cout << endl;
	}

	//check(n, a);
	//return 0;

	fflush(stdout);
	int q; cin >> q;
	while(q--){
		LL k; cin >> k;
		auto res = solve(n, k, a);
		for(auto i: res){
			cout << i.X + 1 << ' ' << i.Y + 1 << endl;
		}
		fflush(stdout);
	}
	
	return 0;
}