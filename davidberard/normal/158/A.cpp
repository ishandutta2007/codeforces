#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	for(auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int c = a[K-1];
	int ans = 0;
	for(int& x : a) {
		if(x >= c && x > 0) ++ ans;
	}
	cout << ans << endl;

	return 0;
}