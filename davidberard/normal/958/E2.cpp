#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int NMAX = 10100, KMAX = 5005;

uint dp[NMAX][KMAX];

const uint INF = 0x3f3f3f3f;

void init() {
	memset(dp, INF, sizeof dp);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int K, N; cin >> K >> N;
	vector<int> vi(N);
	for(int& ii : vi) cin >> ii;
	sort(vi.begin(), vi.end());

	vector<pii> v(N-1);
	vector<pii> cpy(N-1);
	int last = vi[0];
	for(int i=0;i<N-1;++i) {
		int vv = vi[i+1];
		v[i].first = vv-last;
		v[i].second = 0;
		cpy[i] = pii(v[i].first, i);
		last = vv;
	}
	sort(cpy.begin(), cpy.end());
	for(int i=0;i<2*K+2 && i<(N-1);++i) {
		v[cpy[i].second].second = 1;
	}
	vector<uint> w;
	int last_type = 0;
	for(auto & p : v) {
		if(p.second == 1) {
			uint tval = p.first;
			if(!last_type) {
				tval |= (1<<31);
			}
			w.push_back(tval);
			//cerr << p.first << "(" << ((tval & (1<<31)) != 0) << ") ";
			last_type = 1;
		} else {
			last_type = 0;
		}
	}
	//cerr << endl;
	//////cerr << "Getting ready for the dp" << endl;

	dp[0][0] = 0;
	for(int i=1;i<=w.size();++i) {
		for(int j=0;j<=K;++j) {
			dp[i][j] = dp[i-1][j];
			uint tval = w[i-1]&((((uint) 1)<<31)-1);
			bool free_prev = (w[i-1] & ((uint) 1<<31)) != 0;
			if(free_prev || (i==1 && j==1)) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+tval);
			if(j > 0 && i > 1) dp[i][j] = min(dp[i][j], dp[i-2][j-1] + tval);
			//if(i == 1 && j == 1) dp[i][j] = min(dp[i][j], w[i-1]);
			//cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}
	uint best = INF;
	for(int i=0;i<=w.size();++i) {
		best = min(best, dp[i][K]);
	}
	cout << best << endl;

	return 0;
}