#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, k, x[205];
	bool a[205] = {0};
	cin >> t;
	while(t--) {
		fill(a, a+205, 0);
		cin >> n >> k;
		for(int i=1;i<=k;i++) {
			cin >> x[i];
			a[x[i]] = true;
		}
		int ans;
		for(ans=1;;ans++) {
			for(int i=1;i<=k;i++) {
				if(x[i]+(ans-1) <= n) a[x[i]+ans-1] = true;
				if(x[i]-(ans-1) >= 1) a[x[i]-ans+1] = true;
			}
			int s = 0;
			for(int i=1;i<=n;i++) s += a[i];
			if(s == n) break;
		}
		cout << ans << endl;
	}
}