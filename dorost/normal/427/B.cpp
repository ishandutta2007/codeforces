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

int32_t main(){
	int n, t, c;
	cin >> n >> t >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = t + 1;
	n++;
	int x = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > t) {
			ans += max(0, x - c + 1);
			x = 0;
		}else
			x++;
	}
	cout << ans << endl;
}