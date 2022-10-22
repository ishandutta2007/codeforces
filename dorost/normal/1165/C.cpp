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
	int x = n % 2, a = 0;
	bool f[n] = {};
	for (int i = n - 1; i >= 0; i--){
		if (i % 2 == x % 2){
			if (s[i] == s[i + 1]){
				f[i  + 1] =  true;
				a ++;
				x = (x + 1) % 2;
			}
		}
//		cout << x << endl;
	}
	bool h = false;
	if ((n - a) % 2 == 1){
		h = true;
		a++;
	}
	cout << a << endl;
	for (int i = 0; i < n; i++){
		if (!f[i]){
			if (h){
				h = false;
			}else
				cout << s[i];
		}
	}
}