#include <bits/stdc++.h>

#define ll long long
#define lli long long int

using namespace std;

int main(){
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int j = 0; j < n; j++){
		for(int i = 1; i < 5; i++){
			if(s[j][i] == s[j][i - 1] && s[j][i] == 'O'){
				s[j][i] = s[j][i - 1] = '+';
				cout << "YES" << endl;
				for(int k = 0; k < n; k++){
					cout << s[k] << endl;
				}
				return 0;
			}
		}
	}
	cout << "NO";
}