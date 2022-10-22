#include<bits/stdc++.h>

using namespace std;

int n, p[200];
bool mp[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = mp['y'] = 1;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i];
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++){
		getline(cin, s);
		int cnt = 0;
		for (char ch:s)
			if (mp[ch])
				cnt++;
		if (cnt != p[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}