#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long n, m, k, u[500009], v[500009], c[500009], power[1000009], mod = 1000000007; bool used[500009];
map<long long, vector<pair<long long, long long>>>M; vector<long long>vec;
vector<int>X[500009];

void dfs(int pos) {
	if (used[pos] == true) return;
	used[pos] = true;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i]);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &u[i], &v[i]);
		vec.push_back(c[u[i]] ^ c[v[i]]);
		M[c[u[i]] ^ c[v[i]]].push_back(make_pair(u[i], v[i]));
	}
	sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());
	power[0] = 1; for (int i = 1; i <= 1000000; i++) power[i] = (power[i - 1] * 2LL) % mod;

	long long answer = power[k + n];
	for (int i = 0; i < vec.size(); i++) {
		vector<pair<long long, long long>>F = M[vec[i]];
		vector<long long>Z; for (int i = 0; i < F.size(); i++) { Z.push_back(F[i].first); Z.push_back(F[i].second); }
		sort(Z.begin(), Z.end()); Z.erase(unique(Z.begin(), Z.end()), Z.end());

		for (int j = 0; j < F.size(); j++) {
			F[j].first = lower_bound(Z.begin(), Z.end(), F[j].first) - Z.begin();
			F[j].second = lower_bound(Z.begin(), Z.end(), F[j].second) - Z.begin();
		}
		for (int j = 0; j < Z.size(); j++) { X[j].clear(); used[j] = false; }
		for (int j = 0; j < F.size(); j++) { X[F[j].first].push_back(F[j].second); X[F[j].second].push_back(F[j].first); }

		int cnt = 0;
		for (int j = 0; j < Z.size(); j++) {
			if (used[j] == true) continue;
			cnt++;
			dfs(j);
		}
		int V = n - ((int)Z.size() - cnt);
		answer -= (power[n] - power[V]); answer += mod; answer %= mod;
	}
	cout << answer << endl;
	return 0;
}