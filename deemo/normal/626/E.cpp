//Quand le temps va et vient, On ne pense a rien malgre ses blessures..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 2e5 + 10;

ll n, vec[MAXN];
ll p[MAXN];
pair<pair<ld, ll>, ll> ans[MAXN];

ld get(ll ind, ll d){
	ld ret = p[n] - p[n - d];
	ret += vec[ind];
	ret += p[ind] - p[ind - d];
	return	ret/ ld(2 * d + 1);
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	for (ll i = 0; i < n; i++)	p[i + 1] = p[i] + vec[i];

	for (ll i = 0; i < n; i++){
		ll b = -1, e = min(i, n - i - 1);
		while (b < e - 1){
			ll mid = (b + e)>>1;
			ld t1 = get(i, mid), t2 = get(i, mid + 1);
			if (t1 < t2)
				b = mid;
			else
				e = mid;
		}
		ans[i] = {{get(i, b + 1) - (ld)vec[i], b + 1}, i};
	}
	sort(ans, ans + n);
	reverse(ans, ans + n);
	cout << 1 + 2 * ans[0].first.second << "\n";
	for (ll i = n - 1; i >= n - ans[0].first.second; i--)
		cout << vec[i] << " ";
	cout << vec[ans[0].second] << " ";
	for (ll i = ans[0].second - 1; i >= ans[0].second - ans[0].first.second; i--)
		cout << vec[i] << " ";
	cout << "\n";
	return	0;
}