#include<bits/stdc++.h>

int main(){
	long long n, k;
	scanf("%I64d%I64d", &n, &k);
	return printf(n / k & 1 ? "YES\n" : "NO\n"), 0;
}