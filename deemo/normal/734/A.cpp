#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin >> n >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'A')
			a++;
		else
			b++;
	if (a > b)
		cout << "Anton\n";
	if (a < b)
		cout << "Danik\n";
	if (a == b)
		cout << "Friendship\n";
	return 0;
}