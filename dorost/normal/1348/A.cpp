#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a[31], x = 2;
	for (int i = 0; i < 32; i++){
		a[i] = x;
		x *= 2;
	}
	int t = 1;
	cin >> t;
	while (t--){
		int n, s1 = 0, s2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			if (i == n - 1 || i < n / 2 - 1){
				s1 += a[i];
			}else{
				s2 += a[i];
			}
		}
//		cerr << s1 << ' ' << s2 << endl;
		cout << abs(s2 - s1) << endl;
	}
}