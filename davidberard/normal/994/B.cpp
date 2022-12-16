#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct knight {
	static int sort_type;
	int index, power, coins;
	bool operator<(const knight& o) const {
		if(sort_type == 0) return index < o.index;
		if(sort_type == 1) return (power == o.power ? index < o.index : power < o.power);
		return (coins == o.coins ? index < o.index: coins < o.coins);
	}
};

int knight::sort_type = 0;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<knight> knights;
	vector<ll> ans(N);
	for(int i=0;i<N;++i) {
		int p; cin >> p;
		knights.push_back({i, p, 0});
	}
	for(int i=0;i<N;++i) {
		int c; cin >> c;
		knights[i].coins = c;
	}
	knight::sort_type = 1;
	sort(knights.begin(), knights.end());
	knight::sort_type = 2;
	set<knight> kn;
	for(int i=0;i<N;++i) {
		ll sm = knights[i].coins;
		auto it = kn.rbegin();
		for(int j=0;j < K && it != kn.rend();++it) {
			sm += it->coins;
			++j;
		}
		ans[knights[i].index] = sm;
		kn.insert(knights[i]);
	}

	for(ll& ii : ans) {
		cout << ii << " ";
	}
	cout << endl;
	return 0;
}