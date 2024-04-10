#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	long long a, b;
	scanf("%I64d%I64d", &a, &b);
	a = a % (2 * b);
	if (a >= b) printf("YES\n");
	else printf("NO\n");
	return 0;
}