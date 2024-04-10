#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string t = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string s;
	char c;
	cin >> c >> s;
	int x = (c == 'R' ? -1 : +1);
	for (int i = 0; i < s.size(); i++){
		for(int j = 0; j < t.size(); j++){
			if (s[i] == t[j]){
				cout << t[j + x];
			}
		}
	}
}