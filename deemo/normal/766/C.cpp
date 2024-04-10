#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;

int n, c[MAXN], cnt[MAXN], mx[MAXN], mn[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < 26; i++) cin >> c[i], c[i+'a'] = c[i];

	cnt[0] = 1;
	mx[0] = -1, mn[0] = 0;
	for (int i = 0; i < n; i++){
		mx[i + 1] = -1, mn[i + 1] = 1e9;

		int cur = 1e9;
		for (int j = i; ~j; j--){
			cur = min(cur, c[s[j]]);

			if (i-j+1 > cur) break;

			cnt[i + 1] += cnt[j];
			while (cnt[i + 1] >= MOD) cnt[i + 1] -= MOD;
	
			mx[i + 1] = max({mx[i + 1], mx[j], i-j+1});
			mn[i + 1] = min(mn[i + 1], 1+mn[j]);
		}
	}
	
	cout << cnt[n] << "\n";
	cout << mx[n] << "\n";
	cout << mn[n] << "\n";
	return 0;
}