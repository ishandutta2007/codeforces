#include<bits/stdc++.h>

using namespace std;
#define ll long long

int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%lld", c*2ll+min(a, b)*2+(a>b || b>a));
	return 0;
}