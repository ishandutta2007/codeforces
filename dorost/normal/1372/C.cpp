/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];
bool f[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			f[i] = (a[i] != (i + 1));
		}
		int ans = 0;
		if (f[0] == 1)
			ans ++;
		for (int i = 1; i < n; i++){
			if (f[i] == 1 && f[i - 1] == 0)
				ans ++;
		}
		cout << min (ans, 2) << endl;
	}
}