#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	int ret = INT_MIN;
	for (int i = 0; i < n; i++) {
		auto it = upper_bound(all(a),a[i]+5);
		if (it == a.begin()) continue;
		--it;
		ret = max(ret,(it-a.begin())-i+1);
	}
	printf ("%d\n",ret);
    return 0;
}