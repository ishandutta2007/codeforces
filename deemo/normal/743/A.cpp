#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	if (s[--a] == s[--b])
		cout << "0\n";
	else
		cout << "1\n";
	return 0;
}