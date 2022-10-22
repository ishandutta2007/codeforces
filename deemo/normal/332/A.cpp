#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;	cin >> n;
	string s;	cin >> s;
	int ans = 0;
	for (int i = 0; i <  s.size(); i++)
		if (i != 0 && i % n == 0)
			if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3])	ans++;
	cout << ans << endl;
	return 0;
}