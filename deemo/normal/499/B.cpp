#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;


int n, m;
map<string, string>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		string a, b;	cin >> a >> b;
		mp[a] = b;
	}
	while (n--){
		string s;	cin >> s;
		if (s.size() <= mp[s].size())
			cout << s << " ";
		else
			cout << mp[s] << " ";
	}
	cout << "\n";
	return	0;
}