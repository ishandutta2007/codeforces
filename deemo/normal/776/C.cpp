#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const ll INF = 1e16;

ll n, k, sec[MAXN], sz;
map<ll, int> cnt;
ll ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cnt[0]++;

	ll cur = 1;
	for (int i = 0; i < 100; i++){
		if (abs(cur) > INF) break;
		sec[sz++] = cur;
		cur *= k;
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	
	ll p = 0;
	for (int i = 0; i < n; i++){
		ll x;	cin >> x;
		p += x;
		for (int j = 0; j < sz; j++)
			ans += cnt[p - sec[j]];
		cnt[p]++;
	}

	cout << ans << "\n";
	return 0;
}