#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;

inline int logn(int n) {
	int a = 0;
	while(n > 1) {
		++a;
		n /= 2;
	}
	return a;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if(n == 4 && k == 3) {
		cout << "-1\n";
		return;
	}
	vector<bool> used(n);
	int ln = logn(n);
	int x = n-1;
	vector<int> ans;
	if(0 < k && k < n-1) {
		ans.push_back(k);
		ans.push_back(x);
		ans.push_back(x^k);
		ans.push_back(0);
	} else if (k == n-1) {
		for(int i = 0; i < ln; ++i) {
			ans.push_back(1<<i);
			ans.push_back(x^(1<<((i+1)%ln)));
		}
	}
	for(int x : ans)
		used[x] = true;
	for(int i = 0; i < n; ++i) {
		if(!used[i]) {
			ans.push_back(i);
			ans.push_back(x^i);
			used[i] = used[x^i] = true;
		}
	}
	for(int i = 0; i < ans.size(); i += 2) {
		cout << ans[i] << " " << ans[i+1] << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}