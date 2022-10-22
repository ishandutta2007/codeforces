#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, k, lim, a[MAXN];
set<pii> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> lim;
	for (int i = 0; i < n*k; i++) cin >> a[i];
	sort(a, a + n*k);

	ll ans = a[0];
	int cur = 1;
	for (int w = 1; w < n; w++){
		for (int j = cur; j < cur + k && j < n*k; j++)
			st.insert({a[j], j});
		cur = min(cur + k, n*k);

		while (st.size() && st.rbegin()->F > a[0] + lim)
			st.erase(*st.rbegin());

		if (st.empty()){
			cout << "0\n";
			return 0;
		}
		ans += st.rbegin()->F;
		st.erase(*st.rbegin());
	}
	cout << ans << "\n";
	return 0;
}