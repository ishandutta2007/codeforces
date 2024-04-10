#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int32_t main(){
	bool f[26] = {};
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){
		f[tolower(s[i]) - 'a'] = true;
	}
	for (int i = 0; i < 26; i++){
		if (f[i] == false){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}