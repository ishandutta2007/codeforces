/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012345, M = 10;
int a[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ans += a[i] / 10;
		a[i] = (10 - (a[i] % 10));
	}
	for (int i = n; i < N; i++){
		a[i] = M;
	}
	sort (a, a + N);
	int i = 0;
	while (true){
		k -= a[i];
		if (k < 0)
			break;
		ans ++;
		i++;
	}
	cout << min(ans, n * 10) << endl;
}