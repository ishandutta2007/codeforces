#include<bits/stdc++.h>
using namespace std;
const int N(3033);
struct Node {
	Node * s[2], * p;
	int i, j, dp, d;
	Node() {
		s[0] = s[1] = p = NULL;
		i = j = 0;
		dp = 0;
	}
} pool[N * N / 2];
Node * pos[N * N / 2];
int code[N][N];
int a[N];
const int mod = 1e9 + 7;
__inline _(int & a) {
	if(a >= mod) a -= mod;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int np = 0;
	Node * root = new (pool + np++) Node();
	root->dp = 1;
	int nc = 0;
	for(int i(1); i <= n; i++) {
		for(int j(i); j <= n; j++) {
			code[i][j] = nc++;
		}
	}
	for(int i(1); i <= n; i++) {
		Node * p = root;
		for(int j(i); j <= n; j++) {
			if(p->s[a[j]] == NULL) {
				p->s[a[j]] = new (pool + np++) Node();
				p->s[a[j]]->p = p;
				p->s[a[j]]->d = a[j];
			}
			p = p->s[a[j]];
			pos[code[i][j]] = p;
			if(p->i == 0) {
				p->i = i; p->j = j;
			}
		}
	}
	vector<Node * > q;
	q.push_back(root);
	for(int op(0); op < (int)q.size(); op++) {
		Node * v = q[op];
		for(int d(0); d < 2; d++) {
			if(v->s[d] != NULL) q.push_back(v->s[d]);
		}
		if(v->p != NULL) {
			v->dp += v->p->dp;
			_(v->dp);
			if(v->p->p != NULL) {
				v->dp += v->p->p->dp;
			_(v->dp);
				if(v->p->p->p != NULL) {
					v->dp += v->p->p->p->dp;
			_(v->dp);
					if(v->p->p->p->p != NULL) {
						int d = v->p->p->p->d * 8 + v->p->p->d * 4 + v->p->d * 2 + v->d;
						if(d != 3 && d != 5 && d != 14 && d != 15) {
							v->dp += v->p->p->p->p->dp;
			_(v->dp);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= i; j++) {
			Node * p = pos[code[j][i]];
			if(p->i == j && p->j == i) {
				ans += p->dp;
			_(ans);
			}
		}
		printf("%d\n", ans);
	}
}