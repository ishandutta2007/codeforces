#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;

void f(int l, int r, vector<pii>& v) {
	if(!v.size()) return;
	int mx = l - 1;
	vector<pii> lft, rgt;
	for(pii& i : v) {
		if(i.first == l) {
			if(i.second == r) continue;
			mx = max(mx, i.second);
		}
	}
	printf("%d %d %d\n", l, r, mx + 1);
	for(pii& i : v) {
		if(i.first == l && i.second == r) continue;
		if(i.second <= mx) lft.push_back(i);
		else rgt.push_back(i);
	}
	f(l, mx, lft);
	f(mx + 2, r, rgt);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		vector<pii> v;
		for(int i = 1; i <= N; i++) {
			int l, r; scanf("%d%d", &l, &r);
			v.emplace_back(l, r);
		}
		f(1, N, v);
	}
	return 0;
}