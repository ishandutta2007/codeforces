#include <bits/stdc++.h> 
using namespace std;
int main () {
	int n;
	scanf ("%d",&n);
	long long ans = (long long)n*(n+1);
	vector<int> ret(n+1);
	while (n > 0) {
		int lg = __lg(n);
		for (int i = 0; i <= n; i++) ret[i] = (1 << (lg+1)) - 1 - i;
		int next_n = -1;
		for (int i = 0; i <= n; i++) if (ret[i] > n) next_n = i;
		n = next_n;
	}
	if (!n) ret[0] = 0;
	printf ("%lld\n",ans);
	for (int i = 0; i < (int)ret.size(); i++) printf ("%d ",ret[i]);
	return 0;
}