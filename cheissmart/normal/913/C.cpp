#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e18 + 7;

int c[33];

int32_t main()
{
	IO_OP;
	memset(c, 0x3f, sizeof c);
	
	int n, l, s = 0, ans = 0;
	cin >> n >> l;
	for(int i=0;i<n;i++)
		cin >> c[i];
	for(int i=1;i<33;i++)
		c[i] = min(c[i], c[i-1]*2);
	for(int i=32;i>=0;i--)
		if(l>>i&1)
			ans += c[i];	
	for(int i=32;i>=0;i--) {
		if(l>>i&1) {
			s += c[i];	
		} else {
			ans = min(ans, s + c[i]);
		}
	}
	cout << ans << endl;
	
}