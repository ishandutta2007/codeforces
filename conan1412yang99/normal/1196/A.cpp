#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9 + 7;

int32_t main()
{
	
	int q;
	cin >> q;
	while(q--) {
		int a[3], ans = 0;
		for(int i=0;i<3;i++)
			cin >> a[i];
		for(int i=0;i<3;i++)
			for(int j=0;j<i;j++) {
				int x = a[i], y = a[j];
				if(x > y) swap(x, y);
				int k = 0^1^2^i^j;
				int z = a[k];
				int t = (a[0]+a[1]+a[2] + 1) / 2;
				int r = min(z, t - x);
				assert(r >= 0);
				z -= r, x += r;
				y += z;
				ans = max(ans, min(x, y));
			}
		cout << ans << endl;
	}

	return 0;
}