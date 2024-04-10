/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 212;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			a[i] --;
		}
		for (int i = 0; i < n; i++){
			int x = i;
			int y = i;
			int ans = 0;
			while (y != x || ans == 0){
				y = a[y];
				ans ++;
			}
			cout << ans << ' ';
		}
		cout << endl;
	}
}