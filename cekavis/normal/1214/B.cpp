#include<bits/stdc++.h>

using namespace std;
#define ll long long

int b, g, n;
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	scanf("%d%d%d", &b, &g, &n);
	printf("%d\n", min(n, b)-max(0, n-g)+1);
	return 0;
}