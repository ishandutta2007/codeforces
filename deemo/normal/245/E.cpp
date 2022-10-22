#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string s;	cin >> s;
	int c = 0, d = 0;
	vector<char>	st;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '+')
			d++;
		else{
			if (d == 0)	c++;
			else	d--;
		}
	}
	for (int i = 0; i < c; i++)	s = "+" + s;
	d = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '+')
			d++;
		else	d--;
		ans = max(ans, d);
	}
	cout << ans << endl;
	return 0;
}