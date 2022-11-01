#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long INF = (1LL << 60);

int n;

vector<pair<long long, long long> > mem;

int main() {
	scanf("%d", &n);
	long long tt, ww;
	for (int i = 0; i < n; i++) {
		long long t, w;
		scanf("%I64d %I64d", &t, &w);
		if (i == 0) {
			tt = t, ww = w;
		} else {
			mem.push_back({t, w});
		}
	}
	n--;
	sort(mem.begin(), mem.end());
	multiset<long long> higher;
	int ptr = n - 1;
	while (ptr >= 0 && mem[ptr].first > tt) {
		higher.insert(mem[ptr].second - mem[ptr].first);
		ptr--;
	}
	int ans = higher.size() + 1;
	while (tt) {
		//cout << ptr << " " << tt << "higher.size() = " << higher.size() << endl;
		long long tset = INF, tpre = INF;
		ans = min(ans, (int)higher.size() + 1);
		if (!higher.size()) {
			printf("1\n");
			return 0;
		}
		tset = *higher.begin();
		higher.erase(higher.begin());
		if (ptr >= 0) {
			tpre = tt - mem[ptr].first;
		}
		long long final_t = min(tt, min(tpre + 1, tset + 1));
		//cout << "cost = " << final_t << endl;
		tt -= final_t;
		if (tset - final_t >= 0) {
			higher.insert(tset - final_t);
		} else {
			//cout << "delete " << tset << endl;
		}
		while (ptr >= 0 && mem[ptr].first > tt) {
			//cout << "insert new" << mem[ptr].first << endl;
			higher.insert(mem[ptr].second - mem[ptr].first);
			ptr--;
		}
	}
	ans = min(ans, (int)higher.size() + 1);
	printf("%d\n", ans);
	return 0;
}