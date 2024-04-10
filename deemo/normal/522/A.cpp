#include<string>
#include<map>
#include<iostream>

using namespace std;

int n;
map<string, int>	mp;

string convert(string s){
	for (int i = 0; i < s.size(); i++)
		if (s[i] < 'a')
			s[i] += 'a' - 'A';
	return	s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	mp["polycarp"] = 1;
	
	int ans = 1;
	while (n--){
		string a, b, c;	cin >> a >> b >> c;
		a = convert(a);
		c = convert(c);
		mp[a] = mp[c] + 1;
		ans = max(ans, mp[a]);
	}
	cout << ans << endl;
	return 0;
}