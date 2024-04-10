#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

const int MAXN = 1100;

pair<int, int> pairs[MAXN];
int n;
vector<pair<int, int> > ans;

void process(pair<int, int> &a, pair<int, int> &b) {
	ans.push_back(make_pair(b.second, a.second));
	a.first -= b.first;
	b.first *= 2;
}

bool makeLess(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c) {
	if (a.first == 0)
		return false;
	int t = b.first / a.first, r = b.first % a.first;
	for(int i = 0; (1 << i) <= t; i++) {
		if ((1 << i) & t)
			process(b, a);
		else
			process(c, a);
	}
	return true;
}

void moveTo(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c) {
	while(makeLess(a, b, c)) {
		if (c < b)
			swap(b, c);
		if (b < a)
			swap(a, b);
		if (c < b)
			swap(b, c);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1, ID = 1; i <= n; i++, ID++) {
		scanf("%d", &pairs[i].first);
		pairs[i].second = ID;
		if (pairs[i].first == 0) {
			n--;
			i--;
		}
	}
	if (n < 2) {
		printf("-1\n");
		return 0;
	}
	while(n > 2) {
		sort(pairs + 1, pairs + 3 + 1);
		moveTo(pairs[1], pairs[2], pairs[3]);
		swap(pairs[n], pairs[1]);
		n--;
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}