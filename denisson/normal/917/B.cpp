#include <bits/stdc++.h>
				   
using namespace std;
		   
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<pair<int, int> > g[111];
int dp[101][101][26];

int calc(int v1, int v2, int c){
	if (dp[v1][v2][c] != -1) return dp[v1][v2][c];
	int ans = 0;
	for (auto to : g[v1]) if (to.y >= c){
		if (calc(v2, to.x, to.y) == 0){
			ans = 1;
			break;
		}
	}
	return dp[v1][v2][c] = ans;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb(mp(b, c - 'a'));
	}
	for (int w1 = 0; w1 < 101; w1++) for (int s1 = 0; s1 < 26; s1++) for (int w2 = 0; w2 < 101; w2++) dp[w1][w2][s1] = -1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int ans = calc(i, j, 0);
			if (ans) cout << 'A'; else cout << 'B';
		}
		cout << "\n";
	}
}