/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 20;
int a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	int po = pow(2, n);
	for (int i = 0; i < po; i++) {
		int x = i;
		bool f[n];
		for (int j = 0; j < n; j++) {
			f[j] = x % 2;
			x /= 2;
		}
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (f[j]) 
				sum += a[j];
			else
				sum -= a[j];
		}
		sum = abs(sum);
		if (sum % 360 == 0)
			return cout << "yEs", 0;
	}
	cout << "nO";
}