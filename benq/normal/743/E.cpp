#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define pb push_back
#define ub upper_bound

int n, least[256], param[8];
vi test[8];
bool done[256];

int dp(int k) {
	if (done[k]) return least[k];
	F0R(i,8) if (k & (1<<i)) {
		int temp = dp(k^(1<<i));
		if (temp>n) continue;
		if (param[i] == 0) {
			least[k] = min(least[k],temp);
			continue;
		}
		auto it = ub(test[i].begin(),test[i].end(),temp);
		if (distance(it,test[i].end())<param[i]) continue;
		advance(it,param[i]-1);
		least[k] = min(least[k],*it);
	}
	done[k] = 1;
	return least[k];
}

bool ok() {
	F0R(i,256) least[i] = n+1, done[i] = 0;
	least[0] = 0, done[0] = 1;
	if (dp(255) <= n) return 1;
	return 0;
}

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
		int x; cin >> x;
		test[x-1].pb(i);
	}
}

int binsearch() {
	F0R(i,8) param[i] = 1;
	if (!ok()) return 0;
	
	int low = 1, high = n/8;
	while (low<high) {
		int mid = (low+high+1)/2;
		F0R(i,8) param[i] = mid;
		if (ok()) low = mid;
		else high = mid-1;
	}
	return low;
}

int main() {
	input();
	int posi = binsearch();
	int ans = 0;
	F0R(i,256) {
		int ans1 = 8*posi;
		F0R(j,8) {
			param[j] = posi;
			if (i & (1<<j)) param[j] ++, ans1++;
		}
		if (ok()) ans = max(ans,ans1);
	}
	cout << ans;
}