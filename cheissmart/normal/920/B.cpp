#include <bits/stdc++.h>

using namespace std;
int ans[6666];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<pair<int, int>> a(n), b(n);
		fill(ans, ans+n, 0);
		for(int i=0;i<n;i++) {
			int l, r;
			cin >> l >> r;
			a[i] = make_pair(l, i);
			b[i] = make_pair(r, i);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		set<int> s;
		for(int i=0, j=0, k=0;i<=5000;i++) {
			for(;j<n && a[j].first == i; j++)
				s.insert(a[j].second);
			//assign i to a people with least index
			if (s.size()) {
				auto it = begin(s);
				ans[*it] = i;
				s.erase(it);
			}
			for(;k<n && b[k].first == i; k++) {
				auto it = s.find(b[k].second);
				if (it != end(s))
					s.erase(it);
			}
		}
		for(int i=0;i<n;i++) cout << ans[i] << " ";
		cout << endl;
	}	
}