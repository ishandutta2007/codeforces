#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e5 + 10;

ll n, k;
string s, ans;
set<pair<char, ll>>	st;
pair<char, ll>	sec[MAXN];
ll sz = 0, cnt[28];

void get(ll del){
	while (1){
		memset(cnt, 0, sizeof(cnt));
		for (auto it:st)
			cnt[it.F - 'a'] += n - it.S - del;

		ll i;
		for (i = 0; i < 26; i++)
			if (k <= cnt[i])	break;
			else	k -= cnt[i];
		
		ans += char(i + 'a');
		sz = 0;
		for (auto it:st)
			if (it.F - 'a' == i)	sec[sz++] = it;
		st.clear();

		if (sz >= k)	return;
		k -= sz;
		for (ll j = 0; j < sz; j++)
			if (sec[j].S + del + 1 < n)
				st.insert({s[sec[j].S + del + 1], sec[j].S});
		del++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> k;	n = s.size();
	if (ll(n) * ll(n + 1)/ 2LL < k){
		cout << "No such line.\n";
		return 0;
	}

	for (ll i = 0; i < n; i++)
		st.insert({s[i], i});
	get(0);
	cout << ans << "\n";
	return 0;
}