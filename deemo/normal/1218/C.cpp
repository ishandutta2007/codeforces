#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 500 + 5;
const int MAXK = 5e5 + 10;

int n, m, k;
int x[MAXK], y[MAXK], jump[MAXK], t[MAXK], en[MAXK];
ll cost[MAXN][MAXN], dp[MAXN][MAXN][2];
vector<pii> vec[2][MAXN][MAXN];

int dx[4] = {0, 1, 1, 0};
int dy[4] = {0, -1, 0, 1};

void smin(ll &x, ll y){x = min(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		cin >> x[i] >> y[i] >> jump[i] >> t[i] >> en[i];
		int mask = 0;
		for (int w = 0; w < 4; w++){
			int tx = x[i] + dx[w]*jump[i];
			int ty = y[i] + dy[w]*jump[i];
			int req = tx + ty;
			if (req >= t[i] && (req - t[i]) % 4 == w) {
				cost[tx][ty] += en[i];
				mask |= 1<<w;
			}
		}
		if (mask>>2 & 1){
			if (mask&1)
				vec[1][x[i]+dx[2]*jump[i]][y[i]+dy[2]*jump[i]].push_back({x[i], en[i]});
			if (mask>>1&1)
				vec[0][x[i]+dx[2]*jump[i]][y[i]+dy[2]*jump[i]].push_back({y[i] - jump[i], en[i]});
		}
		if (mask>>3&1){
			if (mask&1)
				vec[0][x[i]+dx[3]*jump[i]][y[i]+dy[3]*jump[i]].push_back({y[i], en[i]});
		}
	}

	memset(dp, 63, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = cost[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i+j != n-1+m-1){
				ll sm = 0;
				for (int ti = i+1; ti < n; ti++){
					for (auto v: vec[1][ti][j])
						if (v.F >= i)
							sm -= v.S;
					sm += cost[ti][j];
					smin(dp[ti][j][0], dp[i][j][1] + sm);
				}
				sm = 0;
				for (int tj = j+1; tj < m; tj++){
					for (auto v: vec[0][i][tj])
						if (v.F >= j)
							sm -= v.S;
					sm += cost[i][tj];
					smin(dp[i][tj][1], dp[i][j][0] + sm);
				}
			}

	cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]) << "\n";
	return 0;
}