#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 150000 + 10;
const ll MAXM = 300 + 10;
const ll INF = 1e18;

ll n, m, dis;
ll pos[MAXM], joy[MAXM], tm[MAXM];
ll d[MAXN], c[MAXN];
ll seg[4 * MAXN];
deque<pair<ll, ll>>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> dis;
	for (ll i = 0; i < m; i++){
		cin >> pos[i] >> joy[i] >> tm[i];
		pos[i]--;
	}		
	for (ll i = 0; i < n; i++)
		d[i] = joy[m - 1] - abs(i - pos[m - 1]);
	
	for (ll j = m - 2; j >= 0; j--){
		ll dif = tm[j + 1] - tm[j];
		
		ll b = 0;
		for (ll i = 0; i < n; i++){
			for (; b < n && b <= i + dif * dis; b++){
				while (st.size() && st.back().first <= d[b])
					st.pop_back();
				st.push_back({d[b], b});
			}
			while (st.size() && st.front().second < i - dif * dis)
				st.pop_front();

			ll val = joy[j] - abs(pos[j] - i);	
			c[i] = val + st.front().first;
		}
		copy(c, c + n, d);
		st.clear();
	}
	ll ans = -INF;
	for (ll i = 0; i < n; i++)
		ans = max(ans, d[i]);
	cout << ans << "\n";
	return 0;
}