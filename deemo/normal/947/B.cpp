#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

ll n, a[MAXN], t[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> t[i];

	ll x = 0;
	set<pair<ll, int>> st;
	for (int i = 0; i < n; i++){
		st.insert({a[i] -x, i});
		x -= t[i];
		ll ans = 0;
		while (st.size() && st.begin()->F + x <= 0){
			ans += st.begin()->F + (x+t[i]);
			st.erase(st.begin());
		}
		ans += 1ll*st.size()*t[i];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}