#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct state {
	bool wall;
	int place;
	int water;
	state(bool w, int p, int wa) {
		wall = w;
		place = p;
		water = wa;
	}

	bool operator==(const state& s) const {
		return wall == s.wall && place == s.place && water == s.water;
	}

	bool operator<(const state& s) const {
		if (water == water) {
			if (wall == s.wall)
				return place < s.place;
			return wall < s.wall;
		}
		return water < s.water;
	}
};

int main() {
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	string walls[2];
	cin >> walls[0] >> walls[1];

	priority_queue<state> Q;
	set<state> used;

	Q.push(state(0, 0, 0));
	used.insert(state(0, 0, 0));
	string ans = "NO";
	while (!Q.empty()) {
		state s = Q.top();
		Q.pop();
		if (s.place + k >= n) {
			ans = "YES";
			break;
		}
		//climb down
		if (s.place > 0 && walls[s.wall][s.place - 1] != 'X' && s.place - 1 >= s.water + 1) {
			state s2 = state(s.wall, s.place - 1, s.water + 1);
			if (used.find(s2) == used.end()) {
				Q.push(s2);
				used.insert(s2);
			}
		}
		//climb up
		if (walls[s.wall][s.place + 1] != 'X') {
			state s2 = state(s.wall, s.place + 1, s.water + 1);
			if (used.find(s2) == used.end()) {
				Q.push(s2);
				used.insert(s2);
			}
		}
		//jump across
		if (walls[!s.wall][s.place + k] != 'X') {
			state s2 = state(!s.wall, s.place + k, s.water + 1);
			if (used.find(s2) == used.end()) {
				Q.push(s2);
				used.insert(s2);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}