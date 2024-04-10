#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		multiset<ll> S;
		int N, X; scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			S.insert(a);
		}
		int ans = 0;
		while(S.size()) {
			auto it = S.begin();
			ll t = *it;
			S.erase(it);
			if(S.find(t * X) == S.end()) ans++;
			else S.erase(S.find(t * X));
		}
		printf("%d\n", ans);
	}
	return 0;
}