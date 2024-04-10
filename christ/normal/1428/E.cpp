#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<int> a(n+1);
	auto cost = [&] (int i, int take) {
		++take;
		int go = a[i] / take, extra = a[i] % take;
		if (!go) return (long long)1e18;
		return (long long)extra * (go + 1) * (go + 1) + (long long)(take - extra) * go * go;
	};
	k -= n; long long ans = 0;
	priority_queue<tuple<long long,int,int>> canTake; //{progress,i,take}
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]); ans += cost(i,0);
		canTake.push({cost(i,0) - cost(i,1),i,1});
	}
	while (k--) {
		auto [sub,i,take] = canTake.top(); canTake.pop();
		ans -= sub;
		canTake.push({cost(i,take) - cost(i,take+1),i,take+1});
	}
	printf ("%lld\n",ans);
	return 0;
}