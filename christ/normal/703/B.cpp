#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5, M = 2e4 + 5;
int main () {
	int n,k; scanf ("%d %d",&n,&k);
	vector<int> c(n+1);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&c[i]);
		sum += c[i];
	}
	long long ret = 0;
	for (int i = 1; i <= n; i++) {
		int nxt = i+1;
		if (i == n) nxt = 1;
		ret += (long long)c[i] * c[nxt];
	}
	vector<bool> done(n+1);
	long long sofar = 0;
	while (k--) {
		int x; scanf ("%d",&x);
		long long go = sum - c[x] - sofar;
		if (!done[x==n?1:x+1]) go -= c[x==n?1:x+1];
		if (!done[x==1?n:x-1]) go -= c[x==1?n:x-1];
		ret += (long long)c[x] * go;
		sofar += c[x]; done[x] = true;
	}
	printf ("%lld\n",ret);
	return 0;
}