#include<bits/stdc++.h>

using namespace std;

int main(){
	char lst = '+';
	string s;	cin >> s;
	int ans = 0;

	for (int i = 0; i < s.size(); ){
		int cur = 0;
		while (i < s.size() && s[i] != '-' && s[i] != '+'){
			cur = cur * 10 + (int)(s[i] - '0');
			i++;
		}

		if (lst == '-')
			ans -= cur;
		else
			ans += cur;

	
		if (i < s.size())
			lst = s[i++];
	}
	for (int i = 0; i < 48; i++)
		cout << "+";
	int cur = 0;
	stringstream ss; ss << ans;
	ss >> s;
	for (int i = 0; i < s.size(); i++){
		int x = s[i] - '0';
		while (cur < x) cout << "+", cur++;
		while (cur > x) cout << "-", cur--;
		cout << ".";
	}
	cout << "\n";
	return 0;
}