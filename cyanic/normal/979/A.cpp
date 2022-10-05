#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

int main() {
	LL n;
	scanf("%I64d", &n);
	n++;
	if (n == 1) puts("0");
	else if (n&1) printf("%I64d\n", n);
	else printf("%I64d\n", n/2);
	return 0;
}