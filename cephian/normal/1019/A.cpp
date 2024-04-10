#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 3005;
int p[N], c[N];
vector<int> voters[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> p[i] >> c[i];
		--p[i];
		voters[p[i]].push_back(i);
	}
	for(int i = 0; i < m; ++i) {
		sort(voters[i].begin(), voters[i].end(), [=](const int& a, const int& b) -> bool{
			return c[a] < c[b];
		});
	}
	ll best_cost = 1e17;
	for(int votes = max(1,int(voters[0].size())); votes <= n; ++votes) {
		// get everyone else less than votes
		ll cost  = 0;
		vector<int> leftovers;
		int extra = 0;
		for(int i = 1; i < m; ++i) {
			for(int j = 0; j < int(voters[i].size()); ++j) {
				if(j < ll(voters[i].size()) - votes + 1) {
					cost += c[voters[i][j]];
					++extra;
				} else
					 leftovers.push_back(voters[i][j]);
			}
		}
		sort(leftovers.begin(), leftovers.end(), [=](const int& a, const int& b) -> bool{
			return c[a] < c[b];
		});
		for(int i = 0; i < votes-int(voters[0].size())-extra; ++i)
			cost += c[leftovers[i]];
		best_cost = min(best_cost, cost);
	}
	cout << best_cost << "\n";
}