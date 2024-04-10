#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, u, v;
int a[1005];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		//wtf a[i] >= 1 ???
		scanf("%d%d%d", &n, &u, &v);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		bool closed = 1;
		for (int i = 2; i <= n; i++) if (a[i - 1] - 1 > a[i] || a[i - 1] + 1 < a[i]) { closed = 0; break; }
		if (!closed) { printf("0\n"); continue; }
		bool isline = 1;
		for (int i = 2; i <= n; i++) if(a[i] != a[i - 1]) { isline = 0; break; }
		if (isline) printf("%d\n", v + min(u, v)); else printf("%d\n", min(u, v));
	}
}