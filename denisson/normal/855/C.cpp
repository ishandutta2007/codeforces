#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

const int mod = (int)1e9 + 7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int n, m;
vector<int> g[100007];
int dp[100007][3][11];
int tmp[11];
int c1, c2, c3;
int x, k;

void dfs(int v, int pred){
	for (int to : g[v]) if (to != pred){
		dfs(to, v);
	}

	dp[v][0][0] = c1;
	dp[v][1][1] = c2;
	dp[v][2][0] = c3;

	for (int to : g[v]) if (to != pred){
		for (int i = 0; i < 11; i++) tmp[i] = 0;
		for (int w1 = 0; w1 <= x; w1++){
			for (int w2 = 0; w2 <= x; w2++){
				if (w1 + w2 > x) break;
				add(tmp[w1 + w2], dp[v][0][w1] * (ll)((((dp[to][0][w2] + dp[to][1][w2]) % mod) + dp[to][2][w2]) % mod) % mod);
			}
		}
		for (int i = 0; i < 11; i++) dp[v][0][i] = tmp[i];
		
		for (int i = 0; i < 11; i++) tmp[i] = 0;
		for (int w1 = 0; w1 <= x; w1++){
			for (int w2 = 0; w2 <= x; w2++){
				if (w1 + w2 > x) break;
				add(tmp[w1 + w2], (ll)dp[v][1][w1] * dp[to][0][w2] % mod);
			}
		}
		for (int i = 0; i < 11; i++) dp[v][1][i] = tmp[i];


		for (int i = 0; i < 11; i++) tmp[i] = 0;
		for (int w1 = 0; w1 <= x; w1++){
			for (int w2 = 0; w2 <= x; w2++){
				if (w1 + w2 > x) break;
				add(tmp[w1 + w2], (ll)dp[v][2][w1] * ((dp[to][0][w2] + dp[to][2][w2]) % mod) % mod);
			}
		}
		for (int i = 0; i < 11; i++) dp[v][2][i] = tmp[i];
	}
	/*for (int i = 0; i < 3; i++){
		for (int j = 0; j <= x; j++){
			cout << v + 1 << ' ' << i << ' ' << j << ' ' << dp[v][i][j] << endl;
		}
	}*/
}

int main(){ 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pub(b);
    	g[b].pub(a);
    }
    cin >> k >> x;
    c1 = k - 1;
    c2 = 1;
    c3 = m - k;
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j <= x; j++) add(ans, dp[0][i][j]);
    cout << ans;
}