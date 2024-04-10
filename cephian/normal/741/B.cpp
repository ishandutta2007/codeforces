#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m,W;
ll dp[5005][1005];
int w[1005];
ll b[1005];

bool state[1005]={0};

vvi G;

ll wtsum=0,mxwt=0;
vector<int> reached;
void cc(int v) {
	if(state[v]) return;
	state[v] = 1;
	wtsum += w[v];
	mxwt += ll(b[v]);
	reached.push_back(v);
	for(auto u : G[v])
		cc(u);
}


vector<int> kn_wt;
vector<ll> kn_bt;
vector<int> last_valid;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> m >> W;
	for(int i = 0; i < n; ++i)
		cin >> w[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	G = vvi(n,vi());
	for(int i = 0; i < m; ++i) {
		int x,y;
		cin >> x >> y;
		--x; --y;
		G[x].push_back(y);
		G[y].push_back(x);

	}

	for(int i = 0; i < n; ++i) {
		if(state[i]) continue;
		wtsum=mxwt=0;
		reached.clear();
		cc(i);
		int last_ind = kn_wt.size()-1;
		for(int i = 0; i < reached.size(); ++i) {
			kn_wt.push_back(w[reached[i]]);
			kn_bt.push_back(b[reached[i]]);
			last_valid.push_back(last_ind);
		}
		kn_wt.push_back(wtsum);
		kn_bt.push_back(mxwt);
		last_valid.push_back(last_ind);
	}
	for(int i = 0; i < kn_wt.size(); ++i) {
		for(int wt = 0; wt <= W; ++wt) {
			if(wt == 0)
				dp[i][wt] = 0;
			else {
				dp[i][wt] = dp[i][wt-1];
				//take nothing
				if(i > 0) dp[i][wt] = max(dp[i][wt],dp[i-1][wt]);
				//take single
				if(wt-kn_wt[i] >= 0)
					dp[i][wt] = max(dp[i][wt],kn_bt[i] + ((last_valid[i]==-1)?0:dp[last_valid[i]][wt-kn_wt[i]]));
			}
		}
	}
	cout << dp[kn_wt.size()-1][W] << "\n";


	return 0;
}