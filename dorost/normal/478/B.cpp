/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int unsigned long long

int ans(int x){
	return (x * (x - 1)) / 2;
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	int x = n / m, y = n % m;
	int men = 0, mex = 0;
	men += ans(x + 1) * y + ans(x) * (m - y);
	mex += ans(n - m + 1);
	cout << men << ' ' << mex;
}