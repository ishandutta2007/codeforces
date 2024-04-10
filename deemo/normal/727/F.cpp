//Hameh migan ke to nisti..

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1500 + 10;

int n, q, a[MAXN], sz, ans[MAXN];
ll sec[MAXN];

int get(ll x){
	priority_queue<int, vector<int>, greater<int>> st;
	ll cur = x;
	int ret = 0;
	for (int i = 0; i < n; i++){
		cur += a[i];
		st.push(a[i]);
		while (cur < 0){
			cur -= st.top();
			st.pop();
			ret++;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	ll sm = 0, cur = 0;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sec[0] = 0, ans[0] = get(0), sz++;
	while (ans[sz - 1]){
		ll lo = sec[sz - 1], hi = 1e12;
		while (hi-lo>1){
			ll mid = hi+lo>>1;
			if (get(mid) == ans[sz - 1])
				lo = mid;
			else
				hi = mid;
		}
		sec[sz] = lo+1;
		ans[sz] = get(sec[sz]);
		sz++;
	}
	for (int i = 0; i < sz; i++)
		ans[i] = get(sec[i]);

	while (q--){
		ll x;	cin >> x;
		int pos = upper_bound(sec, sec + sz, x) - sec;
		cout << ans[pos - 1] << "\n";
	}
	return 0;
}