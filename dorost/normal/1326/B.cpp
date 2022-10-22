#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n], b[n], mx = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cout << a[i] + mx << ' ';
		mx = max(mx, a[i] + mx);
	}
}