#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

int n;
string s[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	bool found = 0;
	for (int i = 0; !found && i < n; i++){
		if (s[i][0] == s[i][1] && s[i][1] == 'O')
			s[i][0] = s[i][1] = '+', found = 1;
		else if (s[i][3] == s[i][4] && s[i][4] == 'O')
			s[i][4] = s[i][3] = '+', found = 1;
	}

	if (!found){
		cout << "NO\n";
		return 0;
	}		

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
	return 0;
}