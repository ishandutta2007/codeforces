#include<bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int p[maxn], n;

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &p[i]);
	for (int i=1; i<=n; i++)
		if (p[p[p[i]]] == i) return puts("YES"), 0;
	puts("NO");
	return 0;
}