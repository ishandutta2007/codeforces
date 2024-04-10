#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;	cin >> n >> x;
	ll ans = 0;
	while (n--){
		int y;	cin >> y;
		int z = x^y;
		ans += mp[z];
		mp[y]++;
	}
	cout << ans << endl;
	return 0;
}