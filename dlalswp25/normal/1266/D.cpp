#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
pair<ll, int> D[101010];

vector<pair<pair<int, int>, ll> > ans;

void put(int u, int v, ll d) {
	if(d > 0) ans.push_back({{u, v}, d});
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		D[a].first += c;
		D[b].first -= c;
	}

	for(int i = 1; i <= N; i++) D[i].second = i;
	sort(D + 1, D + N + 1);

	int l = 1, r = N;

	while(l <= r) {
		if(D[r].first < 0) break;
		while(D[r].first > 0) {
			if(D[l].first + D[r].first < 0) {
				put(D[r].second, D[l].second, D[r].first);
				D[l].first += D[r].first;
				D[r].first = 0;
				break;
			}
			else {
				put(D[r].second, D[l].second, -D[l].first);
				D[r].first += D[l].first;
				l++;
			}
		}
		r--;
	}

	printf("%d\n", ans.size());
	for(auto i : ans) printf("%d %d %lld\n", i.first.first, i.first.second, i.second);

	return 0;
}