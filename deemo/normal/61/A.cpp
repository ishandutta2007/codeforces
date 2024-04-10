#include<string>
#include<iostream>

using namespace std;

int main(){
	string s, t, ans = "";
	cin >> s >> t;
	for (int i =0 ;i  < s.size(); i++){
		if (s[i] == t[i])	ans += '0';
		else ans += '1';
	}
	for (int i = 0 ; i < ans.size(); i++)
		cout << ans[i];
	cout << endl;
	return	0;
}