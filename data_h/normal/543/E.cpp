#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 7;
const int SIZE = 400;

int n, m;
int a[N], sum[N], look[N];

struct Block {
	vector<int > pos;
	vector<int > best;
	vector<int > first_v;
	vector<pair<int, pair<int, int> > > keys;
	Block() {
		pos.clear();
		best.clear();
		first_v.clear();
		keys.clear();
	}

	void init() {
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		while (pos.size() && pos.back() >= n) pos.pop_back();
		pos.push_back(n);

		for (int i = 0, pre = 0; i + 1 < pos.size(); i++) {
			int max_v = -1;
			first_v.push_back(pre + sum[pos[i]]);
			for (int j = pos[i]; j < pos[i + 1]; j++) {
				max_v = max(max_v, pre += sum[j]);
			}
			best.push_back(max_v);
		}
	}

	void insert_key(int p, int v, int delta) {
		p = lower_bound(pos.begin(), pos.end(), p) - pos.begin();
		keys.push_back(make_pair(p, make_pair(v, delta)));
	}

	void init_key() {
		sort(keys.begin(), keys.end());
	}

	int query(int l, int r, int v) {
		// for (int i = 0; i + 1 < pos.size(); i++) {
		// 	printf("pos = %d best = %d\n", pos[i], best[i]);
		// }
		// puts("");
		// for (auto d : keys) {
		// 	printf("%d %d %d\n", d.first, d.second.first, d.second.second);
		// }
		// puts("");

		int ans = 0, delta = 0;
		for (int i = 0, ptr = 0; i + 1 < pos.size(); i++) {
			while (ptr < keys.size() && keys[ptr].first <= i) {
				delta += (keys[ptr].second.first >= v) * keys[ptr].second.second;
				ptr++;
			}
			// printf("pos = %d delta = %d\n", pos[i], delta);
			if (r < pos[i] || pos[i + 1] < l) {
				continue;
			} else if (l <= pos[i] && pos[i + 1] <= r) {
				ans = max(ans, delta + best[i]);
			} else {
				for (int j = pos[i], pre = first_v[i] + delta; j < pos[i + 1] && j <= r; j++) {
					if (l <= j && j <= r) {
						ans = max(ans, pre);
					}
					pre -= (a[j] >= v);
					pre += (a[j + m] >= v);
				}
			}
		}
		return ans;
	}
};
vector<Block> blocks;

int main() {
	vector<pair<int, int> > pairs;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pairs.push_back(make_pair(a[i], i));
	}
	sort(pairs.begin(), pairs.end());

	for (int i = n - 1; i >= 0; i--) {
		if (i % SIZE == 0) {
			Block b;
			for (int j = i; j < i + SIZE && j < n; j ++) {
				look[j] = blocks.size();
				int l = max(0, pairs[j].second - m + 1), r = pairs[j].second + 1;
				b.pos.push_back(l);
				b.pos.push_back(r);
			}
			for (int k = 0; k < n; k += SIZE) {
				b.pos.push_back(k);
			}
			b.init();
			for (int j = i; j < i + SIZE && j < n; j ++) {
				int l = max(0, pairs[j].second - m + 1), r = pairs[j].second + 1;
				b.insert_key(l, pairs[j].first, 1);
				b.insert_key(r, pairs[j].first, -1);
				sum[l]++;
				sum[r]--;
			}
			b.init_key();
			blocks.push_back(b);
		}
	}

	int q, ans = 0; scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		l--, r--;
		x ^= ans;
		int t = lower_bound(pairs.begin(), pairs.end(), make_pair(x, -1)) - pairs.begin();
		printf("%d\n", ans = m - blocks[look[t]].query(l, r, x));
	}
	return 0;
}