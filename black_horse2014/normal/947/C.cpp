#include <bits/stdc++.h>
using namespace std;

const int N = 310000;
const int MC = 2;

struct Trie {
	int n, rt;
	int chd[N * 32][MC];
	int en[N * 32];
	
	int newNode() {
		n++;
		fill_n(chd[n], MC, 0);
		en[n] = 0;
		return n;
	}
	
	void init() {
		n = 0;
		rt = newNode();
	}
	
	void insert(int x) {
		int u = rt;
		for (int i = 0; i < 30; i++) {
			int c = (x & (1 << (29 - i))) ? 1 : 0;
			if (!chd[u][c]) chd[u][c] = newNode();
			u = chd[u][c];
			en[u]++;
		}
	}
	
	int go(int x) {
		int u = rt;
		int ret = 0;
		for (int i = 0; i < 30; i++) {
			int c = (x & (1 << (29 - i))) ? 1 : 0;
			if (!chd[u][c] || !en[chd[u][c]]) {
				assert(en[chd[u][!c]]);
				u = chd[u][!c];
				ret |= ((!c) << (29 - i));
			} else {
				u = chd[u][c];
				ret |= (c << (29 - i));
			}
			en[u]--;
		}
		return ret;
	}
} T;

int a[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++) {
		int p; scanf("%d", &p);
		T.insert(p);
	}
	for (int i = 0; i < n; i++) {
		int ret = T.go(a[i]);
		printf("%d ", ret ^ a[i]);
	}
	return 0;
}