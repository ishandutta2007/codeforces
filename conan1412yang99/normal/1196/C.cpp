#include <bits/stdc++.h>
#define MP make_pair
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 100000;


int32_t main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, mxx = INF, mxy = INF, mnx = -INF, mny = -INF;
		cin >> n;
		for(int i=0;i<n;i++) {
			int x, y, f1, f2, f3, f4;
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			if(!f3) {
				mxx = min(mxx, x);
			}
			if(!f4) {
				mny = max(mny, y);
			}
			if(!f1) {
				mnx = max(mnx, x);
			}
			if(!f2) {
				mxy = min(mxy, y);
			}
		}
		if(mxx >= mnx && mxy >= mny) cout << 1 << " " << mnx << " " << mny << endl;
		else cout << 0 <<endl;
	}	

	return 0;
}