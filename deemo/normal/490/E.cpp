#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define FAILURE {cout << "NO\n";	return 0;}

const int MAXN = 1e5 + 10;

int n;
string s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		if (i && s[i].size() < s[i - 1].size())	FAILURE

		if (i == 0 || s[i - 1].size() < s[i].size()){
			if (s[i][0] == '?')	s[i][0] = '1';
			for (int j = 1; j < s[i].size(); j++)
				if (s[i][j] == '?')	s[i][j] = '0';
		}
		else{
			string t;
			bool bg = 0;
			for (int j = 0; j < s[i].size(); j++){
				if (s[i][j] == '?'){
					if (bg){
						s[i][j] = '0';
						continue;
					}

					t = s[i];
					t[j] = s[i - 1][j];
					for (int w = j + 1; w < s[i].size(); w++)
						if (t[w] == '?')	t[w] = '9';

					if (t > s[i - 1])
						s[i][j] = s[i - 1][j];
					else{
						if (s[i - 1][j] == '9')	FAILURE;
						s[i][j] = s[i - 1][j] + 1;
					}
				}

				if (s[i][j] > s[i - 1][j])	bg = 1;
			}
		}

		if (i && s[i].size() == s[i - 1].size() && s[i] <= s[i - 1])	FAILURE
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
	return	0;
}