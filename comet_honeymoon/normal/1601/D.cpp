#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int n;
struct node {
	int a, s;
	bool operator < (const node b) const {
		if (max(a, s) != max(b.a, b.s)) return max(a, s) < max(b.a, b.s);
		if (s != b.s) return s < b.s;
		return a < b.a;
	}
} T[maxn];

int main() {
	int p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) scanf("%d%d", &T[i].s, &T[i].a);
	sort(T + 1, T + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (T[i].s >= p) ans++, p = max(p, T[i].a);
	printf("%d\n", ans);
}