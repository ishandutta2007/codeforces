#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 200005;

int a[N];

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, ans = 0;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		n = unique(a, a+n) - a;
		for(int i=0;i<n;i++) {
			ans = max(ans, a[i]);
			int j = i - 1;
			while(j >= 0 && a[i] % a[j] == 0) j--;
			if(j < 0) continue;
			ans = max(ans, a[i] + a[j]);
			for(int k = j - 1; k >=0; k--)
				if(a[j] % a[k] && a[i] % a[k]) {
					ans = max(ans, a[i] + a[j] + a[k]);
					break;
				}
		}
		cout << ans << endl;
	}

	
}