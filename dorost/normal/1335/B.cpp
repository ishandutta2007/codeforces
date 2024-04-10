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
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		for (int i = 0; i < n; i++){
			s += '#';
		}
		for (int i = 0; i < b; i++){
			s[i] = 'a' + i;
		}
		for (int i = b; i < a; i++){
			s[i] = 'a';
		}
		int x = 0;
		for (int i = a; i < n; i++){
			s[i] = (x % b) + 'a';
			x++;
		}
		cout << s << endl;
	}
}