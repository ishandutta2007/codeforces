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

int __lcm(int a, int b){
	return (a * b / __gcd(a, b));
}

int32_t main(){
	int n;
	cin >> n;
	int cnt[N * 2] = {};
	for (int j = 0; j < n; j++){
		int x;
		cin >> x;
		for (int i = 1; i * i <= x; i++){
			if (x % i)
				continue;
			cnt[i] ++;
			if (i != x / i)
				cnt[x / i]++;
		}
	}
	int ans = 1;
	for (int i = 1; i < N * 2; i++){
//		if (cnt[i]){
//			cerr << i << ' ' << cnt[i] << endl;
//		}
		if (cnt[i] >= n - 1){
			ans = __lcm(ans, i);
		}
	}
	cout << ans << endl;
}