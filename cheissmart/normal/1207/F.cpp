#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[500005], b[606][606];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			a[x] += y;
			for(int i=1;i<600;i++)
				b[i][x%i] += y;
		} else {
			if(x < 600) {
				cout << b[x][y] << endl;
			} else {
				int ans = 0;
				for(int i=y;i<500005;i+=x)
					ans += a[i];
				cout << ans << endl;
			}
		}
	}

	
}