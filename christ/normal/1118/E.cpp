#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MN = 1e6+5, MOD = 998244353;
int main() {
	int n, k;
	scanf ("%d %d",&n,&k);
	if ((long long) k*(k-1) < n) return !printf ("nO\n");
	printf ("yEs\n");
	for (int st = 1; st < k; st++) {
		for (int ed = st+1; ed <= k; ed++) {
			printf ("%d %d\n",st,ed);
			if (!(--n)) return n;
			printf ("%d %d\n",ed,st);
			if (!(--n)) return n;
		}
	}
    return 0;
}