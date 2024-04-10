#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, q;
ll vec[MAXN];
ll ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	cin >> q;

	ll last = 0;
	while (q--){
		ll w, h;	cin >> w >> h;	w--;
		ans[q] = max(vec[w] + h, last + h);
		last = ans[q];
		cout << ans[q] - h << endl;
	}
	return 0;
}