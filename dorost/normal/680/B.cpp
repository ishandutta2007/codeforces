/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 211;
int a[N];
bool f[N];

int32_t main(){
	int n, a;
	cin >> n >> a;
	a--;
	for (int i = 0; i < n; i++){
		cin >> f[i];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++){
		if (i == 0){
			if (f[a])
				ans ++;
		}else{
			int x = 0, y = 0;
			if (a - i >= 0){
				if (f[a - i])
					x++;
				y++;
			}
			if (a + i < n){
				if (f[a + i])
					x++;
				y++;
			}
			if (x == y)
				ans += x;
		}
	}
	cout << ans << endl;
}