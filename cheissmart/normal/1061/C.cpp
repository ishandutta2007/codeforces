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

int dp[1000005], a[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	dp[0] = 1;
	for(int i=0;i<n;i++) {
		basic_string<int> d1,d2;
		for(int j=1;j*j<=a[i];j++) {
			if(a[i] % j == 0) {
				d1.PB(j);
				if(a[i]/j != j)
					d2.PB(a[i]/j);
			}
		}
		reverse(begin(d1),end(d1));
		d2 += d1;
		for (int j : d2) {
			dp[j] += dp[j-1];
			dp[j] %= 1000000007;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		ans += dp[i];
		ans %= 1000000007;
	}
	cout << ans << endl;
}