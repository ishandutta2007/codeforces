#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans = {1};
	int us;
	cin >> us;
	int all = us, co = us;
	for(int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		if(a*2 <= us) {
			ans.push_back(i);
			co += a;
		}
		all += a;
	}
	if(co*2 > all) {
		cout << ans.size() << '\n';
		for(int x : ans)
			cout << x << ' ';
		cout << '\n';
	} else cout << "0\n";
}