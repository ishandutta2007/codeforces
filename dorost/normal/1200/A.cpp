#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	string s;
	cin >> n >> s;
	bool f[10] = {};
	for (int i = 0; i < n; i++){
		if (s[i] == 'L'){
			for (int j = 0; j < 10; j++){
				if (!f[j]){
					f[j] = true;
					break;
				}
			}
		}else if(s[i] == 'R'){
			for (int j = 9; j >= 0; j--){
				if (!f[j]){
					f[j] = true;
					break;
				}
			}
		}else{
			f[s[i] - '0'] = false; 
		}
	}
	for (int i = 0; i < 10; i++){
		cout << f[i];
	}
}