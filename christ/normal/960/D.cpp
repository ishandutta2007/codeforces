#include <bits/stdc++.h>
using namespace std;
long long go (long long x, long long has, long long amount) {
	x += amount;
	while (x >= has * 2) x -= has;
	return x;
}
int main() {//60 levels
	int q;
	scanf ("%d",&q);
	vector<long long> valShift(60), nodeShift(60);
	while (q--) {
		int t; long long x,k;
		scanf ("%d %lld",&t,&x);
		if (t <= 2) {
			scanf ("%lld",&k);
			int level = __lg(x);
			long long has = 1LL << level;
			k = (k%has + has)%has;
			((t == 1 ? valShift : nodeShift)[level] += k) %= has;
		} else {
			int level = __lg(x);
			for (int i = level; i > 0; i--) {
				printf ("%lld ",x);
				long long has = 1LL << i;
				long long totalShift = (valShift[i] + nodeShift[i])%has;
				long long expectedParent = go(x,has,totalShift) / 2;
				long long parentShift = has / 2 - valShift[i-1];
				x = go(expectedParent,has/2,parentShift);
			}
			printf ("1\n");
		}
	}
    return 0;
}