#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int n = s.size();
	for (int i = 1; i < n; i++)
		if (s[i] == s[i - 1]){
			s[i] = 'a';
			while (s[i] == s[i - 1] || (i + 1 < n && s[i] == s[i + 1]))	s[i]++;
		}
	cout << s << "\n";
	return 0;
}