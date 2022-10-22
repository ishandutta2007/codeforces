#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int main () {
	int n,k; scanf ("%d %d",&n,&k);
	vector<int> a(n);
	for (int &i : a) scanf ("%d",&i);
	sort(a.begin(),a.end()); reverse(a.begin(),a.end());
	long long ret = 0;
	for (int i = 0; i < n; i += k) {
		int ed = a[i];
		ret += (ed - 1) * 2;
	}
	printf ("%lld\n",ret);
	return 0;
}