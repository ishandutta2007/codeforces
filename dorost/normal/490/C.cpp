#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000123;
bool f[N], h[N];

int32_t main(){
	string s;
	int a, b, an1 = 0, an2 = 0, n;
	cin >> s >> a >> b;
	n = s.size();
	for (int i = 0; i < n; i++){
		an1 = (an1 * 10 + (s[i] - '0')) % a;
		if (an1 == 0){
			f[i] = true;
		}else
			f[i] = false;
	}
	int x = 1;
	for (int i = n - 1; i >= 0; i--){
		an2 = (an2 + (s[i] - '0') * x) % b;
//		cout << an2 << endl;
		if (an2 == 0 && s[i] != '0'){
			h[i] = true;
		}else{
			h[i] = false;
		}
		x = (x * 10) % b;
	}
//	for (int i = 0; i < n; i++){
//		cout << f[i] << ' ' << h[i] << endl;
//	}
	for (int i = 0; i < n - 1; i++){
		if (f[i] && h[i + 1]){
			cout  << "YES\n";
			for (int j = 0; j <= i; j++) {
				cout << s[j];
			}
			cout << '\n';
			for (int j = i + 1; j < n; j++){
				cout << s[j];
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}