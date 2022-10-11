#include <bits/stdc++.h>
#define lllabs(x) ((x<0) ? -(x) : (x))
using namespace std;

int n, K;

int a[200001];
long long sum[200001];
bool okok[200001];


int main() {
	scanf("%d%d", &n, &K);
	for(int i = 0; i <= n; i++) scanf("%d", &a[i]);
	K = abs(K);

	long long s = 0;
	int ans = 0;


	long long t = 0;
	okok[n] = 1;
	for(int j = n; j > 0; j--) {
		t += a[j];
		t <<= 1;
		sum[j-1] = t;	
		if(lllabs(t) > 1024LL * K) break;
		okok[j-1] = 1;
	}


	for(int k = 0; k <= n; k++) {
	 	if(s&1) break;
		s >>= 1;

		bool ok = okok[k];
		t = sum[k];
		ok = ok && (lllabs(s+t) <= 1LL * K);
		ok = ok && (k != n || s+t != 0);
		if(ok) ans++;

		s += a[k];
	}
	printf("%d\n", ans);
	return 0;
}