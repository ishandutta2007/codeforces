#include <iostream>
#include <vector> 
#include <cassert> 
#include <functional> 
#include <algorithm> 
#include <map> 

bool home = true;
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 7;
int n;
int m;
ll bounty;
ll inc;
ll dmg;

ll limit[N];
ll regen[N];

vector<pair<ll, ll>> theChanges[N];

int main() {

#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> n >> m;
	cin >> bounty >> inc >> dmg;

	for (int i = 1; i <= n; i++) {
		ll init;
		cin >> limit[i] >> init >> regen[i];
		theChanges[i].push_back({ 0, init });
	}

	for (int i_change = 1; i_change <= m; i_change++) {
		ll when;
		int index;
		ll health;
		cin >> when >> index >> health;

		assert(1 <= index && index <= n);

		theChanges[index].push_back({ when, health });
	}

	for (int i = 1; i <= n; i++) {
		sort(theChanges[i].begin(), theChanges[i].end());
	}

	map<ll, ll> events;

	for (int index = 1; index <= n; index++) {
		vector<pair<ll, ll>> changes = theChanges[index];
		changes.push_back({ (ll)2e9, (ll)2e9 });
		int dim = (int)changes.size();
		for (int i = 0; i + 1 < dim; i++) {
			ll t1 = changes[i].first, t2 = changes[i + 1].first;
			ll start = changes[i].second;
			ll l = 1, r = 0;
			if (limit[index] <= dmg) {
				l = t1;
				r = t2 - 1;
			}
			else {
				l = t1;
				if (start > dmg) {
					continue;
				}
				if (!regen[index]) {
					r = t2 - 1;
				}
				else {
					r = min(t2 - 1, l + (dmg - start) / regen[index]);
				}
			}
			if (l > r) continue;
			events[l]++;
			events[r + 1]--;
			if (r == t2 - 1 && i == dim - 2 && inc > 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	ll current = 0, sol = 0;
	for (auto& it : events) {
		sol = max(sol, current * (bounty + inc * (it.first - 1)));
		current += it.second;
	}
	cout << sol << "\n";
}