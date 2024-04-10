#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>

using namespace std;

typedef long long ll;

const ll max_n = 1e5 + 20;

ll n, q;
ll a[max_n];
deque<pair<ll, ll>>	saf;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	while (q--){
		ll l, r;	cin >> l >> r;	l--;
		long long ans = 0, sum = 0;
		for (l++; l < r; l++){
			ll cnt = 1;
			ll x = abs(a[l] - a[l - 1]);
			while (saf.size() && saf.back().first <= x){
				cnt += saf.back().second;
				sum -= saf.back().first * saf.back().second;
				saf.pop_back();
			}
			saf.push_back({x, cnt});
			sum += x * cnt;
			ans += sum;
		}
		cout << ans << endl;
		saf.clear();
	}
	return 0;
}