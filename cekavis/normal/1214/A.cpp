#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, d, e;
int main() {
	scanf("%d%d%d", &n, &d, &e), e*=5;
	int ans=n;
	for(int i=0; i<=n; i+=e) ans=min(ans, (n-i)%d);
	printf("%d\n", ans);
	return 0;
}