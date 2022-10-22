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
int a[N], x;
int n;

int bs (int k) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] > k) {    
			r = mid;      
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

int32_t main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++){
		cin >> x;
		a[i] -= x;
	}
	sort (a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (a[i] <= 0)
			continue;
		int j = bs(-a[i]);
		ans += (i - j);
	}
	cout << ans << endl;
}