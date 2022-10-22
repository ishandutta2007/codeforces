#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN], sm;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > 0)
			sm += a[i];
	}
	if (sm & 1)
		cout << sm << "\n";
	else{
		int mn = 2e9;
		for (int i = 0; i < n; i++)
			if (a[i] > 0 && a[i]&1)
				mn = min(mn, a[i]);
		int ans = sm - mn;
		for (int i = 0; i < n; i++)
			if (a[i] < 0 && a[i]&1)
				ans = max(ans, sm+a[i]);
		cout << ans << "\n";
	}
	return 0;
}