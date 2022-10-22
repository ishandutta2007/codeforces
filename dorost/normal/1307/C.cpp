#include <bits/stdc++.h>

typedef long long ll;
#define F first
#define S second

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s;
	ll cnt[26] = {};
	ll sum[26] = {};
	cin >> s;
	ll ans = 0;
	int n = s.size();
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a'] ++;
	for (int i = 0; i < 26; i++){
		ans = max(ans, cnt[i]);
	}
	for (int i = 0; i < 26; i++){
		cnt[i] = 0;
	}
	for (int k = 0; k < 26; k++){
		for (int i = 0; i < n; i++){
			if(s[i] - 'a' == k){
				for (int j = 0; j < 26; j++){
					sum[j] += cnt[j];
				}
			}
			cnt[s[i] - 'a']++;
		}
		ll mx = 0;
		for (int i = 0; i < 26; i++){
			mx = max(sum[i], mx);
		}
		ans = max(ans, mx);
		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
			sum[i] = 0;
		}
	}
	cout << ans;
}