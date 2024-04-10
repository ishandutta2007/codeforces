#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005], b[100005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=2*n;i++) {
		int t;
		cin >> t;
		if(a[t]) b[t] = i;
		else a[t] = i;
	}
	int ans = 0;
	int x = 1,y = 1;
	for(int i=1;i<=n;i++) {
		if(abs(a[i]-x)+abs(b[i]-y) < abs(a[i]-y)+abs(b[i]-x)) {
			ans += abs(a[i]-x)+abs(b[i]-y);
			x = a[i], y = b[i];
		} else {
			ans += abs(a[i]-y)+abs(b[i]-x);
			y = a[i], x = b[i];
		}
	}
	cout << ans << endl;
}