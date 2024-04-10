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

int a[200005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	int ans = 0, mn = INF;
	for(int i=n-1;i>=0;i--) {
		ans += max(0LL, min(mn, a[i]));
		mn = min(mn, a[i])-1;
	}
	cout << ans << endl;
}