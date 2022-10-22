#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5, MOD = 998244353;
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1); map<int,int> st,ed; vector<int> lst(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), ed[a[i]] = i;
	for (int i = n; i >= 1; i--) st[a[i]] = i; int go = 0;
	for (int i = 1; i <= n; i++) {
		if (i-1 == st[a[i-1]]) lst[i] = ed[a[i-1]];
		lst[i] = max(lst[i],lst[i-1]);
		if (lst[i] < i) ++go;
	}
	int ret = 1;
	while (--go) {
		ret = (ret<<1)%MOD;
	}
	printf ("%d\n",ret);
    return 0;
}