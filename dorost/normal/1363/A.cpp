/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		int f[2] = {};
		for (int i = 0; i < n; i++){
			cin >> a[i];
			f[a[i] % 2]++;
		}
		bool h = false;
		for (int i = 0; i <= f[0]; i++){
			int j = x - i;
			if (j > f[1] || j < 0)
				continue;
			if (j % 2)
				h = true;
		}
		if (h)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}