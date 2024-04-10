#include <bits/stdc++.h>

using namespace std;

int T[5][200005]; // RPS
char S[200005];
int N, Q;
int cv[150];
set<int> P[5];

void update_tree(int t, int x, int v) {
	for(int i = x; i <= N; i += i&-i) T[t][i] += v;
}

int query_tree(int t, int x) {
	int ret = 0;
	for(int i = x; i; i -= i&-i) ret += T[t][i];
	return ret;
}

void update(int x, char c) {
	update_tree(cv[S[x]], x, -1);
	P[cv[S[x]]].erase(x);
	S[x] = c;
	update_tree(cv[c], x, 1);
	P[cv[c]].insert(x);
}

int query_(int a, int b, int c) {
	//c > a > b
	int ret = 0;
	set<int>::iterator it;
	int lc, rc;
	int lb, rb;

	if(P[c].size() == 0) ret = P[a].size();
	else {
		if(P[b].size() == 0) ret = 0;
		else {
			it = P[c].begin();
			lc = (*it);
			it = P[c].end(); it--;
			rc = (*it);
			it = P[b].begin();
			lb = (*it);
			it = P[b].end(); it--;
			rb = (*it);

			if(rc < lb) {
				ret = P[a].size() - (query_tree(a, lb) - query_tree(a, lc));
			}
			else if(rb < lc) {
				ret = P[a].size() - (query_tree(a, rc) - query_tree(a, rb));
			}
			else if(lb < lc && rc < rb) {
				ret = P[a].size();
			}
			else if(lc < lb && rb < rc) {
				ret = P[a].size() - (query_tree(a, rc) - query_tree(a, lc)) + (query_tree(a, rb) - query_tree(a, lb));
			}
			else if(lc < lb && rc < rb) {
				ret = P[a].size() - (query_tree(a, lb) - query_tree(a, lc));
			}
			else {
				ret = P[a].size() - (query_tree(a, rc) - query_tree(a, rb));
			}
		}
	}
	//printf("%d\n", ret);
	return ret;
}

int query() {
	int ret = 0;
	set<int>::iterator it;
	int l, r;
	int _l, _r;

	// calc P win
	if(P[2].size() == 0) ret += P[1].size();
	else {
		if(P[0].size() == 0) {
			it = P[2].begin();
			l = (*it);
			it = P[2].end(); it--;
			r = (*it);
			
			ret += P[1].size() - (query_tree(1, r) - query_tree(1, l - 1));
		}
		else {
			it = P[0].begin();
			l = (*it);
			it = P[0].end(); it--;
			r = (*it);

			ret += query_tree(1, r) - query_tree(1, l - 1);

			it = P[2].begin();
			l = min(l, (*it));
			it = P[2].end(); it--;
			r = min(r, (*it));

			ret += query_tree(1, l) + query_tree(1, N) - query_tree(1, r - 1);
		}
	}

	// calc S win
	if(P[0].size() == 0) ret += P[2].size();
	else {
		if(P[1].size() == 0) {
			it = P[0].begin();
			l = (*it);
			it = P[0].end(); it--;
			r = (*it);
			
			ret += P[2].size() - (query_tree(2, r) - query_tree(2, l - 1));
		}
		else {
			it = P[1].begin();
			l = (*it);
			it = P[1].end(); it--;
			r = (*it);

			ret += query_tree(2, r) - query_tree(2, l - 1);

			it = P[0].begin();
			l = min(l, (*it));
			it = P[0].end(); it--;
			r = min(r, (*it));

			ret += query_tree(2, l) + query_tree(2, N) - query_tree(2, r - 1);
		}
	}

	// calc R win
	if(P[1].size() == 0) ret += P[0].size();
	else {
		if(P[2].size() == 0) {
			it = P[1].begin();
			l = (*it);
			it = P[1].end(); it--;
			r = (*it);
			
			ret += P[0].size() - (query_tree(0, r) - query_tree(0, l - 1));
		}
		else {
			it = P[2].begin();
			l = (*it);
			it = P[2].end(); it--;
			r = (*it);

			ret += query_tree(0, r) - query_tree(0, l - 1);

			it = P[1].begin();
			l = min(l, (*it));
			it = P[1].end(); it--;
			r = min(r, (*it));

			ret += query_tree(0, l) + query_tree(0, N) - query_tree(0, r - 1);
		}
	}
	return ret;
}

int q() {
	return query_(0, 2, 1) + query_(1, 0, 2) + query_(2, 1, 0);
}

int main() {
	cv['R'] = 0, cv['P'] = 1, cv['S'] = 2;
	scanf("%d%d", &N, &Q);
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i++) {
		update_tree(cv[S[i]], i, 1);
		P[cv[S[i]]].insert(i);
	}

	printf("%d\n", q());
	while(Q--) {
		int x; char c;
		scanf("%d %c", &x, &c);
		update(x, c);
		printf("%d\n", q());
	}

	return 0;
}