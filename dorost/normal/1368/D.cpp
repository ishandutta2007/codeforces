/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];
bool b[20][N];

int32_t main(){
	int n, su = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		int x = a[i];
		for (int j = 0; j < 20; j++){
			b[j][i] = x % 2;
			x /= 2;
		}
		su += a[i];
	}
	for (int i = 0; i < 20; i++){
		sort (b[i], b[i] + n);
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < 20; j++){
//			cerr << b[j][i];
//		}
//		cerr << endl;
//	}
	int an = 0;
	for (int i = 0; i < n; i++){
		int ans = 0;
		for (int j = 19; j >= 0; j--){
			ans *= 2;
			ans += b[j][i];
		}
		an += ans * ans;
//		cerr << ans << ' ';
	}
//	cerr << endl;
	cout << an;
}