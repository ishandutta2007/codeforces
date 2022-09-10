#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 6;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool used[N][N];
int cnt;
char s[N][N];
char ans[N][N];

bool ok(int x, int y){
	return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1 && !used[x][y] && s[x][y] == '.';
}

void dfs(int x, int y, bool res){
	used[x][y] = 1;
	cnt++;
	if (res){
		ans[x][y] = '*';
	}
	
	FOR(k, 0, 4){
		int i = x + dx[k], j = y + dy[k];
		if (ok(i, j)){
			dfs(i, j, res);
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int k;
	cin >> n >> m >> k;
	FOR(i, 0, N) FOR(j, 0, N) s[i][j] = '.';
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) cin >> s[i][j];
	dfs(0, 0, 0);
	
	vector<pair<int, PII>> vec;
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) if (ok(i, j)) {
		cnt = 0;
		dfs(i, j, 0);
		vec.PB({cnt, {i, j}});
	}
	
	sort(ALL(vec));
	assert(SZ(vec) >= k);
	FOR(it, 0, k) vec.pop_back();
	
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) ans[i][j] = s[i][j];
	
	int A = 0;
	FILL(used, 0);
	for(auto hto: vec){
		A += hto.X;
		int x = hto.Y.X, y = hto.Y.Y;
		dfs(x, y, 1);
	}
	
	cout << A << endl;
	FOR(i, 1, n + 1){
		FOR(j, 1, m + 1) cout << ans[i][j];
		cout << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}