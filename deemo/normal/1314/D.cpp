#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 80 + 3;

int n, k;
int adj[MAXN][MAXN];
vector<pii> best[MAXN][MAXN];
int ans = 2e9;

int q[10];
short mark[MAXN];
void go(int ind) {
	if (ind == k) {
		int cur = 0;
		for (int i = 0; cur <= ans && i < k; i++) {
			int u = q[i], v = q[i+1==k?0:i+1];
			int j = 0;
			while (mark[best[u][v][j].S]) j++;
			cur += best[u][v][j].F;
		}
		ans = min(ans, cur);
		return;
	}

	for (int v = 0; v < n; v++) {
		q[ind] = v;
		mark[v]++;
		go(ind+1);
		mark[v]--;
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int w = 0; w < n; w++)
				best[i][j].push_back({adj[i][w] + adj[w][j], w});
			sort(best[i][j].begin(), best[i][j].end());
			best[i][j].resize(min(n, k/2 + 1));
		}
	k /= 2;

	q[0] = 0;
	mark[0] = 1;
	go(1);
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}