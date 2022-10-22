#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, s, a[MAXN], t;
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s, s--;
	set<int>	st;
	for (int i = 0; i < n; i++)	st.insert(i);
	for (int i = 0; i < n; i++)	cin >> a[i];
	if (a[s])	t++, a[s] = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		st.erase(a[i]);

	for (int i = 1; i < n; i++)
		if (!a[i] || a[i] >= n){
			int z = 1;
			if (st.size())
				z = *st.begin(), st.erase(st.begin());

			a[i] = z, mark[i] = 1, t++;
		}
	sort(a, a + n);

	int cur = 0, cnt = 0, c2 = 0;
	int ans = 1e9;
	for (int i = 0; i < n; i++){
		while (cur < n && a[cur] <= i)	cnt++, cur++;
		while (st.size() && *st.begin() <= i){
			c2++;
			st.erase(st.begin());
		}
		ans = min(ans, t + max(c2, n - cnt));
	}

	cout << ans << "\n";
	return 0;
}