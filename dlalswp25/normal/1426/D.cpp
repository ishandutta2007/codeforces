#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, int> mp;

int main() {
	int N; scanf("%d", &N);
	int ans = 0;
	ll s = 0;
	mp[0]++;
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		s += a;
		if(mp[s]) {
			ans++;
			mp.clear();
			mp[0]++;
			mp[a]++;
			s = a;
		}
		else mp[s]++;
	}
	printf("%d\n", ans);
	return 0;
}