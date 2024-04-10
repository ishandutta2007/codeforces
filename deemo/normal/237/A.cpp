#include<iostream>
#include<map>
#include<utility>

using namespace std;

int ans = 0;
map<pair<int, int>, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	while (n--){
		int a, b;	cin >> a >> b;
		ans = max(ans, ++mp[{a, b}]);
	}
	cout << ans << "\n";
	return	0;
}