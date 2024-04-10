#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
int main() {
	scanf("%d%d", &n, &k), k=(n-k)/2+1;
	for(int i=1; i<=n; ++i) putchar('0'+!(i%k));
	return 0;
}