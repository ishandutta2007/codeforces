#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n;
	int b = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		b += a;
	}
	cin >> m;
	int ans = 0x7fffffff;
	for(int i = 0; i < m; ++i) {
		int l,r;
		cin >> l >> r;
		if(r >= b) {
			ans = min(ans,max(l,b));
		}
	}
	if(ans ==0x7fffffff) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}