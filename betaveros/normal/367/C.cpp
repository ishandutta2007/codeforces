#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define fori(i,s,e) for (int i = s; i < ((int)e); i++)

vector<int> costs;
int n;
int m;
void readInput() {
	scanf("%d %d", &n, &m);
	fori (i, 0, m) {
		int _, cost;
		scanf("%d %d", &_, &cost);
		costs.push_back(cost);
	}
}
inline int c2(int x) { return x * (x-1) / 2; }
int requiredLength(int nDistinct) {
	if (nDistinct % 2 == 0) {
		return c2(nDistinct) + nDistinct / 2;
	} else {
		return c2(nDistinct) + 1;
	}
}
int maxDistinct(int len) {
	int lo = 0, hi = 2001;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (requiredLength(mid) <= len) lo = mid; else hi = mid;
	}
	return lo;
}
long long maxCost() {
	sort(costs.begin(), costs.end(), greater<int>());
	int md = min(maxDistinct(n), (int) costs.size());
	long long ret = 0;
	fori (i, 0, md) ret += costs[i];
	return ret;
}

int main() {
	readInput();
	printf("%" PRId64 "\n", maxCost());
}