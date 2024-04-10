#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >>N ;
	vector<int> a(N);
	for(auto& ii : a) cin >> ii;
	pii ans(2e9, 1000);
	for(int i=0;i<N;++i) {
		if(a[i] <= i) {
			ans = min(ans, pii(i, i+1));
		}
		else {
			ans = min(ans, pii(((a[i]-i+N-1)/N)*N, i+1));
		}
	}
	cout << ans.second << endl;

	return 0;
}