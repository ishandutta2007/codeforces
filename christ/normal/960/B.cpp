#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k1,k2;
	scanf ("%d %d %d",&n,&k1,&k2);
	int k = k1 + k2;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	priority_queue<int> have;
	for (int i = 1; i <= n; i++) {
		int b; scanf ("%d",&b); a[i] = abs(a[i] - b); have.push(a[i]);
	}
	while (k--) {
		int cur = have.top(); have.pop();
		if (cur == 0) cur++;
		else cur--;
		have.push(cur);
	}
	long long ret = 0;
	while (!have.empty()) {
		ret += (long long)have.top() * have.top();
		have.pop();
	}
	printf ("%lld\n",ret);
    return 0;
}