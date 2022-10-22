/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int l, r, m;
		cin >> l >> r >> m;
		for (int a = l; a <= r; a++){
			int n = m / a;
			int x = m % a;
			int b = r;
			int c = r - x;
			if (n * a + b - c == m && min (b, c) >= l && max (b, c) <= r && n > 0){
				cout << a << ' ' << b << ' ' << c << endl;
				goto Y;
			}
		}
		for (int a = l; a <= r; a++){
			int n = (m + a - 1) / a;
			int x = n * a - m;
			int b = l;
			int c = l + x;
			if (n * a + b - c == m && min (b, c) >= l && max (b, c) <= r && n > 0){
				cout << a << ' ' << b << ' ' << c << endl;
				goto Y;
			}
		}
		return -1;
		Y :
		cout << "";
	}
}