#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	s += '0';
	for(int i=0;i<n;i++) {
		if(s[i] > s[i+1]) {
			cout << s.substr(0, i) + s.substr(i+1, n-i-1) << endl;
			return 0;
		}
	}
	
}