#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n;
map<int, int>	mp;
ll ans;

int get(int x){
	if (x == 0)	return	0;
	if (x % 2 == 0)	return	get(x/2);
	return	get(x/2) + 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--){
		int temp;
		cin >> temp;
		temp = get(temp);
		ans += mp[temp];
		mp[temp]++;
	}
	cout << ans << endl;
	return 0;
}