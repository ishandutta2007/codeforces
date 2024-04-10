#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5, K = 22;
int a[N];
ll dp[K][N]={},A;
int L=0,R=0;
int freq[N] = {};

inline void remove(int x) {
	A -= --freq[x];
}

inline void add(int x) {
	A += freq[x]++;
}

inline void slide(int l, int r) {
	while(l < L) add(a[--L]);
	while(R < r) add(a[++R]);
	while(L < l) remove(a[L++]);
	while(r < R) remove(a[R--]);
}


void compute(int k, int l, int r, int bl, int br) {
	int m = (l+r)/2, o;
	dp[k][m]= 1LL<<62;
	for(int i = bl; i <= min(br,m); ++i) {
		slide(i,m);
		ll cost = A + dp[k-1][i-1];
		if(cost < dp[k][m])
			dp[k][m] = cost, o = i;
	}
	if(l <= m-1) compute(k,l,m-1,bl,o);
	if(m+1 <= r) compute(k,m+1,r,o,br);
}

#define lld I64d;

int main() {	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i)
		scanf("%d",a+i);
	L = R = 1, A = 0;
	freq[a[1]] = 1;
	for(int i = 1; i <= n; ++i) {
		slide(1,i);
		dp[1][i] = A;
	}

	for(int l = 2; l <= k; ++l) {
		compute(l,1,n,1,n);
	}
	printf("%lld\n",dp[k][n]);
}