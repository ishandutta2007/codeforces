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

int a[300005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int d = 0, ans = 0;
	for(int i=0;i<n;i++) {
		int c = min(a[i] / 2, d);
		d -= c, ans += c;
		a[i] -= c * 2;
		ans += a[i] / 3;
		a[i] %= 3;
		d += a[i];
	}
	cout << ans << endl;
}