#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, SUB = 5e3 + 1;
int n;
int query (int l, int r) {
	r = min(r,n);
	printf ("? %d %d\n",l,r);
	fflush(stdout);
	int ret; scanf ("%d",&ret);
	return r - l + 1 - ret;
}
int main () {
	int t; scanf ("%d %d",&n,&t);
	int k; scanf ("%d",&k);
	int low = 1, high = n, mid, ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (query(1,mid) >= k) high = (ans = mid) - 1;
		else low = mid + 1;
	}
	printf ("! %d\n",ans);
	fflush(stdout);
	return 0;
}