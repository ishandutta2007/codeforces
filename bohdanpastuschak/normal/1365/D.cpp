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
mt19937 rng(58);

const int N = 1 << 6;
int n, m;
string s[N];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

inline bool ok(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

char used[N][N];

void dfs(int x, int y){
	used[x][y] = 1;
	FOR(k, 0, 4){
		int i = x + dx[k], j = y + dy[k];
		if (!ok(i, j) || used[i][j] || s[i][j] == '#') continue;
		dfs(i, j);
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		FOR(i, 0, n) cin >> s[i];
		
		bool ans = true;
		
		FOR(i, 0, n) FOR(j, 0, m) if (s[i][j] == 'B'){
			FOR(k, 0, 4){
				int x = i + dx[k], y = j + dy[k];
				if (!ok(x, y)) continue;
				if (s[x][y] == 'G'){
					ans = false;
				}else{
					if (s[x][y] == '.'){
						s[x][y] = '#';
					}
				}
			}			
		}
		
		FILL(used, 0);
		if (s[n - 1][m - 1] != '#')
			dfs(n - 1, m - 1);
			
		FOR(i, 0, n) FOR(j, 0, m) if (s[i][j] == 'G') ans &= used[i][j];		
		
		cout << (ans ? "Yes\n" : "No\n");
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}