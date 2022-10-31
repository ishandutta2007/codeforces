#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> mp;
int n, l, cc[100005][26];
int HH[100005], id[100005], cnt[100005];
char str[1000005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", str);
		l = strlen(str);
		for (int j = 0; j < l; j++)
			cc[i][str[j] - 'a']++;
		for (int j = 0; j < 26; j++)
			cc[i][j] = cc[i][j] & 1;
		for (int j = 0; j < 26; j++)
			HH[i] = HH[i] * 2 + cc[i][j];
		mp[HH[i]] = 1;
	}
	int tot = 0;
	for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++)
		it -> second = ++tot;
	for (int i = 1; i <= n; i++) {
		id[i] = mp[HH[i]];cnt[id[i]]++;}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cnt[id[i]]--;
		for (int j = 0; j < 26; j++)
			if (mp.find(HH[i] ^ (1 << j)) != mp.end())
				ans += cnt[mp[HH[i] ^ (1 << j)]];
		ans += cnt[id[i]];
	}
	printf("%I64d\n", ans);
	return 0;
}