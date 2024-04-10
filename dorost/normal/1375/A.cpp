/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 102;
int a[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i % 2){
				a[i] = max(a[i], -a[i]);
			}else{
				a[i] = min (a[i], -a[i]);
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}