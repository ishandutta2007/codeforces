#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 60 + 3;

int n, d[MAXN], ln;
string s;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret *= a;
		b >>= 1;
		a *= a;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	ln = s.size();
	memset(d, 63, sizeof(d));
	d[ln] = 0;
	for (int i = ln-1; ~i; i--){
		ll cur = 0;
		for (int j = i; j < ln && cur < n; j++){
			cur = cur*10ll+int(s[j] - '0');
			if (cur < n)
				d[i] = min(d[i], 1 + d[j + 1]);
			if (j == i && cur == 0)
				break;
		}
	}
	ll ans = 0;
	for (int i = 0; i < ln;){
		ll cur = 0;
		int j = i;
		while (d[i] < 1+d[j + 1])
			cur = cur * 10ll + int(s[j++] - '0');
		cur = cur*10ll+int(s[j++]-'0');
		ans += cur * pw(n, d[i]-1);
		i = j;
	}
	cout << ans << "\n";
	return 0;
}