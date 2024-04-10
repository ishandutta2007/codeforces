#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, vec[MAXN];
ll a[MAXN], b[MAXN];
multiset<ll>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		a[i + 1] = a[i], b[i + 1] = b[i];
		if (vec[i] >= 0)	a[i + 1] += vec[i];
		else	b[i + 1] += -vec[i];
	}
	
	st.insert(0);
	for (ll i = 0; i < n; i++)
		st.insert(b[i] - a[i]);
	ll ans = a[n] - b[n];
	ll aa = 0, bb = 0;
	for (ll i = n - 1; i >= 0; i--){
		ll ret = bb - aa + a[i + 1] - b[i + 1];
		auto it = st.end();	it--;
		ret += *it * 2;
		ans = max(ans, ret);

		if (vec[i] > 0)	aa += vec[i];
		else	bb += -vec[i];
		st.erase(st.find(b[i] - a[i]));
	}

	ans = max(ans, b[n] - a[n]);
	cout << ans << "\n";
	return	0;	
}