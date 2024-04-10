#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int EP = 131;
const int PRE = 0;
const int DEL = 1;

const int N = 333333;

long long treeL[N << 2], treeR[N << 2];
long long power[N << 2];
int a[N << 2], n;

void update(int x, int l, int m, int r) {
	treeL[x] = 1LL * treeL[x << 1] * power[r - m] + treeL[x << 1 | 1];
	treeR[x] = 1LL * treeR[x << 1 | 1] * power[m - l + 1] + treeR[x << 1];
}

void build(int x, int l, int r) {
	if (l == r) {
		treeL[x] = treeR[x] = PRE;
		return ;
	}
	int m = (l + r) / 2;
	build(x << 1, l, m);
	build(x << 1 | 1, m + 1, r);
	//update(x, l, m, r);
}


void modify(int x, int l, int r, int pos) {
	if (l == r) {
		treeL[x] = treeR[x] = DEL;
		return ;
	}
	int m = (l + r) / 2;
	if (pos <= m) {
		modify(x << 1, l, m, pos);
	} else {
		modify(x << 1 | 1, m + 1, r, pos);
	}
	update(x, l, m, r);
}

long long getL(int x, int l, int r, int ql, int qr) {
	if (qr < l || ql > r) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return 1LL * treeL[x] * power[qr - r];
	}
	
	int m = (l + r) / 2;
	
	return (getL(x << 1, l, m, ql, qr) + getL(x << 1 | 1, m + 1, r, ql, qr));
}

long long getR(int x, int l, int r, int ql, int qr) {
	if (qr < l || ql > r) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return treeR[x] * power[l - ql];
	}
	
	int m = (l + r) / 2;
	
	return (getR(x << 1, l, m, ql, qr) + getR(x << 1 | 1, m + 1, r, ql, qr));
}

int main() {
	scanf("%d", &n);
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	power[0] = 1;
	for(int i = 1; i <= n; i++) {
		power[i] = 1LL * power[i - 1] * EP;
	}
	for(int i = 1; i <= n; i++) {
		modify(1, 1, n, a[i]);
		int len = min(a[i] - 1, n - a[i]);
		if (getL(1, 1, n, a[i] - len, a[i] - 1) != getR(1, 1, n, a[i] + 1, a[i] + len)) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}