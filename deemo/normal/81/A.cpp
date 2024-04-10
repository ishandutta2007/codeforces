#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans, s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (ans.empty() || ans.back() != s[i])	ans += s[i];
		else	ans.pop_back();
	}
	cout << ans << "\n";
	return	0;
}