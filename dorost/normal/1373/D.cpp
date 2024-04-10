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
int a[N], b[N];


int submax(int l, int m, int h) { 
	int sum = 0; 
	int sum0 = INT_MIN; 
	for (int i = m; i >= l; i--){ 
		sum = sum + b[i]; 
		if (sum > sum0) 
			sum0 = sum;
	} 
	sum = 0;
	int sum1 = INT_MIN; 
	for (int i = m + 1; i <= h; i++) { 
		sum = sum + b[i]; 
		if (sum > sum1) 
			sum1 = sum; 
	} 
	return max({sum0 + sum1, sum0, sum1}); 
} 

int submx(int l, int h){ 
	if (l == h) 
		return b[l]; 
	int m = (l + h) /2; 
	return max({submx(l, m), submx(m+1, h), submax(l, m, h)}); 
} 

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = 0;
		}
		for (int i = 0; i < n - 1; i += 2){
			b[i] = a[i + 1] - a[i];
		}
		int mx = submx(0, n - 1);
		for (int i = 0; i < n; i++){
			b[i] = 0;
		}
		for (int i = 1; i < n - 1; i += 2){
			b[i] = a[i] - a[i + 1];
		}
		mx = max(mx, submx(0, n - 1));
		for (int i = 0; i < n; i += 2){
			mx += a[i];
		}
		cout << mx << endl;
	}
}