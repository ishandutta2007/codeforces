#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		bool f = true;
		for (int i = 1; i < s.size(); i++){
			if (s[i] != s[i - 1]){
				f = false;
			}
		}
		if (f){
			cout << s << endl;
			continue;
		}else{
			for (int i = 0; i < s.size(); i++){
				cout << "10";
			}
			cout << endl;
		}
	}
}