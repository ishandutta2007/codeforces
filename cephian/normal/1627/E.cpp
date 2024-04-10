#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5;
ll x[N];

int s_floor[N];
int s_room[N];
int e_floor[N];
int e_room[N];
ll health[N];
ll max_in[N];

const ll INF = 1LL<<62;
const ll NINF = -INF;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	vector<vector<int>> touch(n+2);
	for(int i = 0; i < k; ++i) {
		cin >> s_floor[i] >> s_room[i] >> e_floor[i] >> e_room[i] >> health[i];
		touch[s_floor[i]].push_back(i);
		touch[e_floor[i]].push_back(i);
	}
	fill(max_in, max_in+k, NINF);

	s_floor[k] = -1;
	s_room[k] = 1;
	e_floor[k] = 1;
	e_room[k] = 1;
	health[k] = 0;
	max_in[k] = 0;
	touch[1].push_back(k);

	s_floor[k+1] = n;
	s_room[k+1] = m;
	e_floor[k+1] = n+1;
	e_room[k+1] = m;
	health[k+1] = 0;
	max_in[k+1] = NINF;
	touch[n].push_back(k+1);

	for(int f = 1; f <= n; ++f) {
		sort(touch[f].begin(), touch[f].end(), [f](int a, int b) -> bool {
				int af = (s_floor[a] == f) ? s_room[a] : e_room[a];
				int bf = (s_floor[b] == f) ? s_room[b] : e_room[b];
				return af < bf;
			});

		ll out_loc = NINF;
		ll out_hlt = NINF;
		auto proc = [&](int i) {
			int cur = touch[f][i];
			if(s_floor[cur] == f) {
				// starts here
				if(out_loc != NINF) {
					max_in[cur] = max(max_in[cur], out_hlt - abs(out_loc - s_room[cur])*x[f]);
				}
			} else {
				// ends here
				ll take_old = (out_loc != NINF) ? out_hlt - abs(out_loc - e_room[cur])*x[f] : NINF;
				ll take_new = (max_in[cur] != NINF) ? max_in[cur] + health[cur] : NINF;
				if(take_new >= take_old) {
					out_loc = e_room[cur];
					out_hlt = take_new;
				}
			}
		};
		// sweep forward
		for(int i = 0; i < touch[f].size(); ++i)
			proc(i);

		// sweep backwards
		out_loc = 0;
		out_hlt = NINF;
		for(int i = touch[f].size()-1; i >= 0; --i)
			proc(i);
	}
	if(max_in[k+1] == NINF) cout << "NO ESCAPE" << endl;
	else cout << -max_in[k+1] << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}