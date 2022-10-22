/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;

int32_t main(){
	int n;
	cin >> n;
	int a[2][n];
	for (int i = 0; i < n; i++)
		cin >> a[0][i];
	for (int i = 0; i < n; i++)
		cin >> a[1][i];
	int mx[N] = {0, a[0][0]}, mx1[N] = {0, a[1][0]};
	for (int i = 2; i <= n; i++){
		for (int ch = 0; ch < 2; ch++){
			if (ch == 0){
				mx[i] = a[0][i - 1] + max(mx1[i - 1], mx1[i - 2]);
			}else{
				mx1[i] = a[1][i - 1] + max(mx[i - 1], mx[i - 2]);
			}
		}
	}
	cout << max(mx1[n], mx[n]);
}