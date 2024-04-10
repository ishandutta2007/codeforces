#include<bits/stdc++.h>
using namespace std;

template <class T> inline void read(T &x) {
	x = 0; bool flag = 0; char ch = getchar(); for (; !isdigit(ch); ch = getchar()) if (ch == 45) flag = 1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48; if (flag) x = -x;
}

#define N 2944731
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define ll long long

int l, r, p, pri[101], cnt, n, a[N], f[N];
bool b[N];
bool notPri[101];

void getNum(int x, int k) {
	a[++n] = x;
	rep(j, k, cnt) if ((ll)x * pri[j] <= r) getNum(x * pri[j], j); else return;
}

int main() {
//	freopen("calculetor.in", "r", stdin);
//	freopen("calculetor.out", "w", stdout); 
	read(l), read(r), read(p);
	rep(i, 2, p - 1) {
		if (!notPri[i]) pri[++cnt] = i;
		rep(j, 1, cnt) {
			if (i * pri[j] >= p) break;
			notPri[i * pri[j]] = 1;
			if (!(i % pri[j])) break;
		}
	}
	getNum(1, 1); sort(a + 1, a + 1 + n);
	memset(f, 0x3f, sizeof f); f[1] = 0;
	rep(i, 2, p - 1) {
		int k = 1;
		rep(j, 1, n) if (!(a[j] % i)) {
			while (a[k] * i < a[j]) k++;
			if ((f[j]  = min(f[j], f[k] + 1)) + i <= p) b[j] = 1;
		}
	}
	int ans = 0; rep(i, 1, n) if (b[i] && a[i] >= l) ans++;
	printf("%d", ans);
	return 0;
}