#include <bits/stdc++.h>
#define N ((int)2e5 + 87)

using namespace std;

pair<int,int> a[N];

int main()
{
	int n, k, x, y;
	cin >> n >> k;
	set<int> s;
	vector<vector<int>> hate(n+1);
	vector <int> ans(n);
	for(int i=0;i<n;i++) cin >> a[i].first, a[i].second = i;
	for(int i=0;i<k;i++) {
		cin >> x >> y;
		x--, y--;
		hate[x].push_back(y);
		hate[y].push_back(x);
	}
	sort(a, a+n, greater<pair<int,int>>());
	for(int i=n-1;i>=0;) {
		int cur = a[i].first, j = i;
		while(i >= 0 && a[i].first == cur) {
			i--;
		}
		for(int k = i+1;k <= j;k++) {
			int ch = 0;
			for(int h:hate[a[k].second])
				ch += s.count(h);
			ans[a[k].second] = s.size() - ch;
		}
		for(int k = i+1; k <= j;k++)
			s.insert(a[k].second);
	}
	for(int i:ans) cout << i << " ";
	cout << endl;
}