#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 100005;
int t[maxn*305][2], low[maxn*305], root[maxn];
int Q, op, x, k, s, size;

void insert(int u, int val) {
	per (i, 17, 0) {
		if (!t[u][val>>i&1]) {
			t[u][val>>i&1] = ++size;
			low[size] = 1e6;
		}
		u = t[u][val>>i&1];
		low[u] = min(low[u], val);
	}
}

int query(int u, int limit, int XOR) {
	if (limit <= 0) return -1;
	int val = 0, need;
	per (i, 17, 0) {
		need = ((XOR >> i) & 1) ^ 1;
//		printf("%d\n", i);
		if (t[u][need] && low[t[u][need]] <= limit) {
			u = t[u][need];
			val += (need << i);
		}
		else if (t[u][need^1] && low[t[u][need^1]] <= limit) {
			u = t[u][need^1];
			val += ((need^1) << i);
		}
		else return -1;
	}
	return !val ? -1 : val;
}

int main() {
	scanf("%d", &Q);
	rep (i, 1, 100000) root[i] = ++size;
	while (Q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			for (int i=1; i*i<=x; i++)
				if (x % i == 0) {
					insert(root[i], x);
					if (i * i != x)
						insert(root[x/i], x);
				}
		}
		else {
			scanf("%d%d%d", &x, &k, &s);
			if (x % k > 0) { puts("-1"); continue; }
			printf("%d\n", query(root[k], s-x, x));
		}
	}
	return 0;
}