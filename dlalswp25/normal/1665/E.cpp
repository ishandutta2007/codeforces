#include <bits/stdc++.h>

using namespace std;

const int B = 30;

int N, Q;
int A[101010];

struct Node {
	int v, l, r;

	Node() : v(0), l(0), r(0) {}
};

struct PTrie {
	Node T[3232323];
	int rt[101010];
	int id = 0;
	int n = 0;

	void init() {
		for(int i = 1; i <= id; i++) T[i] = Node();
		id = n = 0;
	}

	int upd(int bef, int s, int e, int p) {
		if(p < s || e < p) return bef;
		int now = ++id;
		if(s == e) {
			T[now].v = T[bef].v + 1;
			return now;
		}
		int m = s + e >> 1;
		T[now].l = upd(T[bef].l, s, m, p);
		T[now].r = upd(T[bef].r, m + 1, e, p);
		T[now].v = T[T[now].l].v + T[T[now].r].v;
		return now;
	}

	void add(int x) {
		n++;
		rt[n] = upd(rt[n - 1], 0, (1 << B) - 1, x);
	}

	int find(int b, int l, int r, int cur) {
		if(b < 0) return cur;
		if(T[T[r].l].v - T[T[l].l].v) return find(b - 1, T[l].l, T[r].l, cur);
		return find(b - 1, T[l].r, T[r].r, cur | 1 << b);
	}

	int query(int l, int r) {
		int lv = rt[l - 1], rv = rt[r];
		vector<int> vs;
		int ans = 0;
		for(int i = B - 1; i >= 0; i--) {
			int cnt = T[T[rv].l].v - T[T[lv].l].v;
			int tmp = cnt;
			for(int j : vs) {
				if(~j & 1 << i) cnt++;
			}
			if(cnt >= 2) {
				vector<int> nv;
				for(int j : vs) {
					if(~j & 1 << i) nv.push_back(j);
				}
				vs = nv;
				lv = T[lv].l; rv = T[rv].l;
			}
			else {
				if(tmp == 1) vs.push_back(find(i - 1, T[lv].l, T[rv].l, ans));
				ans |= 1 << i;
				lv = T[lv].r; rv = T[rv].r;
			}
		}
		return ans;
	}
}trie;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		trie.init();
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			trie.add(a);
		}
		scanf("%d", &Q);
		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			printf("%d\n", trie.query(l, r));
		}
	}
	return 0;
}