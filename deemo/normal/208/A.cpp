#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;	cin >> s;
	string ans = "";
	for (int i = 0; i < (int)s.size();){
		if (i < (int)s.size() - 2 && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
			i += 3;
			if (ans.size() && ans.back() != ' ')
				ans += ' ';
			continue;
		}
		ans += s[i];
		i++;
	}
	cout << ans << endl;
	return 0;
}