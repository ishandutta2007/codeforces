#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

map<char, pair<int, int>>	mp;

int main(){
	char dir;	cin >> dir;
	string s;	cin >> s;
	string a[3];
	a[0] = "qwertyuiop";
	a[1] = "asdfghjkl;";
	a[2] = "zxcvbnm,./";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < a[i].size(); j++)
			mp[a[i][j]] = {i, j};
	for (int i = 0; i < s.size(); i++){
		char c = s[i];
		if (dir == 'L')
			s[i] = a[mp[c].first][mp[c].second + 1];
		else
			s[i] = a[mp[c].first][mp[c].second - 1];
	}
	cout << s << endl;
	return 0;
}