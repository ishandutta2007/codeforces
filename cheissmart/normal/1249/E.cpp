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

int a[200005], b[200005];

int32_t main()
{
	IO_OP;
	
	int n, c;
	cin >> n >> c;
	for(int i=1;i<n;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int i=1;i<n;i++) {
		cin >> b[i];
		b[i] += b[i-1];
	}
	int mnx = 0, mny = c, mnyx = 0, mnxy = c;
	vi ans({0});
	for(int i=2;i<=n;i++) {
		int aa = a[i-1] + min(mnx, mnxy);
		int bb = b[i-1] + min(mny, mnyx+c);
		mnx = min(mnx, aa - a[i-1]);
		mny = min(mny, bb - b[i-1]);
		mnyx = min(mnyx, aa - b[i-1]);
		mnxy = min(mnxy, bb - a[i-1]);
		ans.PB(min(aa, bb));
	}
	for(int e:ans) cout << e << " ";
	
}