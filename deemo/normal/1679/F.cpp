#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

const int MAXN = 5e4 + 10;

int n, m, adj[10];

int dp[2][1<<10];
int allow1[10], allow2[10];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < 10; i++)
        adj[i] = 1<<i;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a] |= 1<<b;
        adj[b] |= 1<<a;
    }
    for (int i = 0; i < 10; i++) {
        allow1[i] = (1<<10)-1 ^ adj[i] ^ 1<<i;
        allow2[i] = (1<<10)-1 ^ allow1[i];
        for (int j = i+1; j<10; j++)
            allow2[i] &= -1 ^ 1<<j;
    }

    int cur = 0;
    dp[cur][(1<<10)-1] = 1;
    for (int i = 0; i < n; i++, cur ^= 1) {
        memset(dp[!cur], 0, sizeof(dp) / 2);  // XXX?
        for (int mask = 1; mask < 1<<10; mask++)
            if (dp[cur][mask])
                for (int j = 0; j < 10; j++)
                    if (mask>>j&1)
                        add(dp[!cur][allow1[j] | allow2[j] & mask], dp[cur][mask]);
    }


    int ans = 0;
    for (int i = 0; i < 1<<10; i++)
        add(ans, dp[cur][i]);
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