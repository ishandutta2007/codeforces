#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		string s;
		cin >> n >> k >> s;
		int cnt[26] = {};
		for (int i = 0; i < n; i++){
			cnt[s[i] - 'a'] ++;
		}
		int mx = -1;
		for (int i = 1; i <= n; i++){
			int count = 0;
			for (int j = 0; j < 26; j++){
				count += (cnt[j] / i);
			}
			for (int j = 1; j <= count; j++){
				int num = j * i;
				if (__gcd(num, k) % j == 0){
					mx = max(mx, num);
				}
			}
		}
		cout << mx << '\n';
	}
}