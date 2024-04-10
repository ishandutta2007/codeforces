#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int tans[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
void prep() {
	assert(sizeof tans > 4*25);
}
int solve(int x) {
	int ans = 32 - __builtin_clz(x);
	ans = (1<<ans)-1;
	if(32 - __builtin_clz(x) == __builtin_popcount(x)) {
		ans = tans[32-__builtin_clz(x)];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	prep();
	int N;
	cin >> N;
	for(int i=0;i<N;++i) {
		int a;
		cin >> a;
		cout << solve(a) << "\n";
	}
	return 0;
}