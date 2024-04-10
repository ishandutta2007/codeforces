#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct Node {
	Node *ch[28], *f;
	int len, cnt, level;
	Node(int len = 0) {
		memset(ch, 0, sizeof ch);
		level = 0;
		f = NULL; cnt = 0; this->len = len;
	}
};
int ga;
struct PT {
	Node pool[maxn];
	int sz;
	Node* newnode(int len = 0) {
		pool[sz] = Node(len);
		return &pool[sz++];
	}
	Node *last, *m1;
	int s[maxn];
	int n;
	void init() {
		sz = 0;
		last = newnode(0);
		last->f = newnode(-1);
		pool[1].f = last->f;
		s[n = 0] = -1;
		ga = 0;
	}
	Node *get_fail(Node *x) {
		while(s[n - x->len - 1] != s[n]) {
			x = x->f;
		}
		return x;
	}
	void add(int c) {
		c = c + 1 - 'a';
		s[++n] = c;
		Node *u = get_fail(last);
		if(!u->ch[c]) {
			Node *p = newnode(u->len + 2);
			p->f = get_fail(u->f)->ch[c];
			if(!p->f) p->f = &pool[0];
			p->level = p->f->level + 1;
			u->ch[c] = p;
		}
		last = u->ch[c];
		last->cnt++;
		ga += last->level;
	}
	void count() {
		for(int i = sz - 1; i > 1; --i) pool[i].f->cnt += pool[i].cnt;
		pool[0].cnt = pool[1].cnt = 0;
	}
} pt;
char s[5010];
int ans[5010][5010] = {{}};
int main() {
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; ++i) {
		pt.init();
		for(int j = i; j < l; ++j) {
			pt.add(s[j]);
			ans[i][j] = ga;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", ans[l-1][r-1]);
	}
	return 0;
}