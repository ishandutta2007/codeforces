#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

map<int, int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int w = 0; w < 2; w++){
		int n; cin >> n;
		while (n--){
			int x, y; cin >> x >> y;
			mp[x] = max(mp[x], y);
		}
	}
	ll ans = 0;
	for (auto x:mp)
		ans += x.S;
	cout << ans << "\n";
	return 0;
}