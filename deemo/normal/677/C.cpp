#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 10;

ll n;
string s;

ll get(char c){
	ll id = 0;
	if ('0' <= c && c <= '9')	id = c - '0';
	else if ('A' <= c && c <= 'Z')	id = 10 + (c - 'A');
	else if ('a' <= c && c <= 'z')	id = 36 + (c - 'a');
	else if (c == '-')	id = 62;
	else id = 63;

	ll cnt = 6;
	for (ll i = 0; i < 6; i++)
		if ((id>>i)&1)	cnt--;
	ll ret = 1;
	while (cnt--)
		ret = (ret * 3LL) % MOD;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	ll ans = 1;
	for (ll i = 0; i < n; i++)
		ans = (ans * get(s[i])) % MOD;
	cout << ans << endl;
	return 0;
}