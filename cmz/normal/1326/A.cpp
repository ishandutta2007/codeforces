#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
int main() {
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld",&n);
		if (n==1) {
			printf("-1\n");
			continue;
		}
		for (int i=2; i<n; i++) printf("2");
		if ((n-1)%9==0) printf("99\n");
		else printf("29\n");
	}
	return 0;
}