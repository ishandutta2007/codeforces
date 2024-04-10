#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, mx = -10000000, sum = 0;
	cin >> n;
	bool a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	for (int i = 0; i < n; i++){
		int ans = 0;
		for (int j = i; j < n; j++){
			if (a[j] == 1)
				ans --;
			else
				ans ++;
			mx = max (ans, mx);
		}
	}
	cout << mx + sum;
}