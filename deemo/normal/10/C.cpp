//Never left without saying goodbye..

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 2e6 + 10;

ll n, cnt[20], gg[MAXN];
ll ans;

ll gd(ll x){return (x%9==0)?9:x%9;}

int main(){
	cin >> n;
	for (int i = 1; i <= n + 200; i++)	gg[i] = gd(i);
	for (ll i = 1; i <= n; i++)	cnt[gd(i)] ++;
	for (ll i = 1; i <= n; i++){
		for (ll a = 1; a < 10; a++)
			for (ll b = 1; b < 10; b++)
				if (gg[a * b] == gg[i])
					ans += cnt[a] * cnt[b];
	}
	for (ll i = 1; i <= n; i++)
		for (ll j = i; j <= n; j += i)
			if (gg[gg[i] * gg[j/i]] == gg[j])	ans--;
	cout << ans << "\n";
	return	0;
}