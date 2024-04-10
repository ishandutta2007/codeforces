/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200;
int a[N];
string b[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = "";
		}
		b[n] = "";
		for (int i = 0; i < 55; i++){
			b[0] += 'a';
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < a[i]; j++){
				b[i + 1] += b[i][j];
			}
			for (int j = a[i]; j < 55; j++) {
				b[i + 1] += ((i % 25) + 'b');
			}
		}
		for (int i = 0; i < n + 1; i++){
			cout << b[i] << endl;
		}
	}
}