#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

ll a[100005], dp1[100005], dp2[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	ll mx = max(dp1[0] = abs(a[1] - a[0]),
		        dp2[0] = abs(a[1] - a[0]) * -1);
	for(int i=1;i<n-1;i++) {
		dp1[i] = max(dp1[i-1], 0LL) + abs(a[i+1] - a[i]) * (i&1 ? -1 : 1);
		dp2[i] = max(dp2[i-1], 0LL) + abs(a[i+1] - a[i]) * (i&1 ? 1 : -1);
		mx = max(mx, dp1[i]);
		mx = max(mx, dp2[i]);
	}
	cout << mx << endl;
}