/*
n,T

1n,,
2,w,h
wb
h1

*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 500009;
int w[maxn*2]; char s[maxn];
int n, a, b, T, l, r, sum, ans;

int main(){
	scanf("%d%d%d%d%s", &n, &a, &b, &T, s+1);
	for (int i=1; i<=n; i++){
		if (s[i] == 'w') w[i] = w[n+i] = b+1;
		else w[i] = w[n+i] = 1;
		sum += w[i];
	}
	l = 2; r = n+1;
	while (l <= n+1 && r <= 2*n){
		while (r-l+1 > n || sum+(r-l+min(r-n-1, n+1-l))*a > T)
			sum -= w[l++];
		ans = max(ans, r-l+1);
		sum += w[++r];
	}
	printf("%d\n", ans);
	return 0;
}