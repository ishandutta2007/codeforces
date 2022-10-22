#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

int n;
string s;
map<pair<int, int>, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	mp[{0, 0}] = 1;
	int a = 0, b = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'L')	a++;
		if (s[i] == 'R')	a--;
		if (s[i] == 'U')	b++;
		if (s[i] == 'D')	b--;
		ans += mp[{a, b}]++;
	}
	cout << ans << "\n";
	return	0;	
}