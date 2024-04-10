#include <bits/stdc++.h>
#define N (int) 3e5 + 1

using namespace std;

long long a[N], b[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	long long x = 0, y = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		x += t;
		a[i] = x;
	}
	cin >> m;
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		y += t;
		b[i] = y;
	}
	if(x != y) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 0, j = 0;i < n && j < m;i++) {
		for(;j<m && b[j] < a[i];j++);
		ans += (b[j] == a[i]);
	}
	cout << ans << endl;
	
}