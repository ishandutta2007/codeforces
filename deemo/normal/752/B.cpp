#include<bits/stdc++.h>

using namespace std;

vector<pair<char, char>>	vec;
int mp[300];

int main(){
	string s, t;	cin >> s >> t;
	memset(mp, -1, sizeof(mp));
	for (int i = 0; i < s.size(); i++){
		if (mp[s[i]] == -1 || mp[s[i]] == t[i]){
			if (mp[s[i]] == -1)
				s += t[i], t += s[i];
			mp[s[i]] = t[i];
		}
		else{
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 'a'; i <= 'z'; i++){
		if (mp[i] == -1)
			mp[i] = i;
		if (mp[i] != i){
			if (mp[mp[i]] != i){
				cout << "-1\n";
				return 0;
			}
			if (mp[i] > i)
				vec.push_back({char(i), char(mp[i])});
		}
	}
	
	cout << vec.size() << endl;
	for (auto x:vec)
		cout << x.first << " " << x.second << endl;
	return 0;
}