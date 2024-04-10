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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[300005], b[300005], nxta[300005], nxtb[300005], lsta[300005], lstb[300005];

int32_t main()
{
	IO_OP;
	
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for(int i=1;i<=n;i++) {
		if(s[i-1] == 'A') a[i] = 1;
		else b[i] = 1;
	}
	int aa = n, bb = n;
	for(int i=n-1;i>=0;i--) {
		nxta[i+1] = aa + 1;
		nxtb[i+1] = bb + 1;
		if(s[i] == 'A') aa = i;
		else bb = i;
	}
	aa = -1, bb = -1;
	for(int i=0;i<n;i++) {
		lsta[i+1] = aa + 1;
		lstb[i+1] = bb + 1;
		if(s[i] == 'A') aa = i;
		else bb = i;
	}
	for(int i=1;i<=n;i++) {
		a[i] += a[i-1];
		b[i] += b[i-1];
	}
	for(int i=1;i<=n;i++) {
		if(s[i-1] == 'A') ans += nxtb[i] - i - 1;
		else ans += nxta[i] - i - 1;
		int l = i, r = n;
		while(l <= r) {
			int m = ( l + r) / 2;
			int aa = a[m] - a[i-1], bb = b[m] - b[i-1];
			if(aa <= 1 || bb <= 1) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		ans += n - r;
		int la, lb, ra, rb;
		la = i - lstb[i] - 1, lb = i - lsta[i] - 1;
		ra = nxtb[i] - i - 1, rb = nxta[i] - i - 1;
	
		if(s[i-1] == 'B')ans += la * ra;
		else ans += lb * rb;
	}
	cout << ans << endl;
}