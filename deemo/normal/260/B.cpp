#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN = 1e5 + 10;

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int>	mp;

bool ok(string s){
	if (s[2] != '-' || s[5] != '-')	return	false;
	for (int i = 0; i < 10; i++)
		if (s[i] == '-' && (i != 2 && i != 5))	return	false;
	int t = 0;
	for (int i = 0; i < 2; i++)
		t = (t * 10 + (s[i] - '0'));
	if (t == 0)	return	false;
	int z = 0;
	for (int i = 3; i < 5; i++)
		z = (z * 10 + (s[i] - '0'));
	if (z < 1 || z > 12)	return	false;
	z--;
	if (t > m[z])	return	false;
	int y = 0;
	for (int i = 6; i < 10; i++)
		y = (y * 10 + (s[i] - '0'));
	if (y < 2013 || y > 2015)	return	false;
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int mx = 0;
	string ans;
	for (int i = 0; i <= s.size() - 10; i++){
		string t;
		for (int j = 0; j < 10; j++)	t += s[i + j];
		if (ok(t)){
			mp[t]++;
			if (mp[t] > mx){
				mx = mp[t];
				ans = t;
			}
		}
	}
	cout << ans << "\n";
	return	0;
}