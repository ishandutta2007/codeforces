#include <bits/stdc++.h>

#define MAXN (300010)

int n;
int a[MAXN];
struct node {
	node *go[2];
	int cnt;
	
	node() {
		go[0] = go[1] = NULL;
		cnt = 0;
	}
}*root;

void insert(node* p, int x) {
	for (int i = 29; ~i; -- i) {
		int c = (x >> i) & 1;
		if (! p -> go[c]) {
			p -> go[c] = new node();
		}
		p = p -> go[c];
		++ p -> cnt;
	}
}

int query(node *p, int x) {
	int ret = 0;
	for (int i = 29; ~i; -- i) {
		int c = (x >> i) & 1;
		if (p -> go[c] && p -> go[c] -> cnt) {
			p = p -> go[c];
		}
		else {
			p = p -> go[c ^ 1];
			ret |= 1 << i;
		}
		-- p -> cnt;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", a + i);
	}
	root = new node();
	for (int i = 1; i <= n; ++ i) {
		int p;
		scanf("%d", &p);
		insert(root, p);
	}
	for (int i = 1; i <= n; ++ i) {
		printf("%d%c", query(root, a[i]), " \n"[i == n]);
	}
	return 0;
}