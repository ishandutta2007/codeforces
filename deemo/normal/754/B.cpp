#include<bits/stdc++.h>

using namespace std;

string s[5];

bool check(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j <= 1; j++)
			if (s[i][j] == 'x' && s[i][j] == s[i][j+1] && s[i][j + 1] == s[i][j + 2])	return true;
	for (int j = 0; j < 4; j++)
		for (int i = 0; i <= 1; i++)
			if (s[i][j] == 'x' && s[i][j] == s[i + 1][j] && s[i + 1][j] == s[i + 2][j])	return true;
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			if (s[i][j] == s[i + 1][j + 1] && s[i + 1][j + 1] == s[i + 2][j + 2] && s[i][j] == 'x')	return true;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i + 2 < 4 && j - 2 >= 0)
				if (s[i][j] == 'x' && s[i + 1][j - 1] == 'x' && s[i + 2][j - 2] == 'x')	return true;
	return false;
}

int main(){
	for (int i = 0; i < 4; i++)	cin >> s[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (s[i][j] == '.'){
				s[i][j] = 'x';
				if (check()){
					cout << "YES\n";
					return 0;
				}
				s[i][j] = '.';
			}
	cout << "NO\n";
	return 0;
}