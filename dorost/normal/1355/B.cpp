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
int a[N], cnt[N];

int32_t main(){
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i <= n + 10; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			cnt [a[i]] ++;
		}
		int ans = 0, bag = 0;
		for (int i = 1; i <= n; i++){
			ans += (cnt[i] + bag) / i;
			bag = (cnt[i] + bag) % i;
		}
		cout << ans << endl;
	}
}