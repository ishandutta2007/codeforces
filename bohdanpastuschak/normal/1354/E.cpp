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
const LL INF = 1e9;
const LL LINF = INF * INF;
 
const int N = 5000 + 7;
int n, m;
int c1, c2, c3;
VI g[N];
int color[N];
vector<vector<int>> all_black, all_white;
vector<int> white, black;


void dfs(int v, int c){
	color[v] = c;
	if (c == 1){
		white.PB(v);
	}else{
		black.PB(v);
	}
	
	for(auto i: g[v]){
		if (color[i] == 0){
			dfs(i, 3 - c);
		}
		
		if (color[i] == color[v]){
			cout << "NO" << endl;
			exit(0);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
	cin >> n >> m;
	cin >> c1 >> c2 >> c3;
	
	while(m--){
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}

	vector<pair<int, int>> A;
	FOR(i, 0, n){
		if (color[i] == 0){
			dfs(i, 1);
			all_black.PB(black);
			all_white.PB(white);
			
			A.PB({SZ(white), SZ(black)});
			black.clear();
			white.clear();
		}
	}
	
	
	vector<vector<char>> dp(SZ(A) + 1, vector<char>(n + 1, 0));
	vector<vector<char>> batya(SZ(A) + 1, vector<char>(n + 1, 0));
	
	dp[0][0] = 1;
	FOR(i, 0, SZ(A)){
		int x = A[i].X, y = A[i].Y;
		FOR(j, 0, n + 1) if (dp[i][j]){
			dp[i + 1][j + x] = true;
			batya[i + 1][j + x] = false;
			
			dp[i + 1][j + y] = true;
			batya[i + 1][j + y] = true;
			
		}
	}	
	
		
	if (dp[SZ(A)][c2] == false){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	vector<char> de_braty;
	for(int de = SZ(A), zara = c2; de > 0; de--){
		if (batya[de][zara] == false){
			de_braty.PB(0);
			zara -= A[de - 1].X;
		}else{
			de_braty.PB(1);
			zara -= A[de - 1].Y;
		}
	}
	
	reverse(ALL(de_braty));
	
	vector<int> ans(n, 0);
	
	FOR(i, 0, SZ(A)){
		if (de_braty[i] == 0){
			for(auto j: all_white[i]){
				ans[j] = 2;
			}
			
			for(auto j: all_black[i]){
				if (c1){
					c1--;
					ans[j] = 1;
				}else{
					ans[j] = 3;
				}
			}
		}else{
			for(auto j: all_black[i]){
				ans[j] = 2;
			}
			
			for(auto j: all_white[i]){
				if (c1){
					c1--;
					ans[j] = 1;
				}else{
					ans[j] = 3;
				}
			}
		}
	}
	
	for(auto i: ans){
		cout << i;
	}
	
	cout << endl;
	
  
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}