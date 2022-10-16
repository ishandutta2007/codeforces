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

const int INF = 1e18 + 7;

int neg, pos;
int a[500005];

int32_t main()
{
	IO_OP;
	
	int n, mn = INF;
	cin >> n;
	int ans = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		ans += abs(a[i]);
		if(a[i] > 0) pos++;
		if(a[i] < 0) neg++;
		mn = min(mn, abs(a[i]));
	}
	if(n == 1) {
		cout << a[0] << endl;
	} else if(pos == n || neg == n) {
		cout << ans - mn*2 << endl;
	} else {
		cout << ans << endl;
	}
	
}