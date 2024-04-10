#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[500005], dp[500005];

int main()
{
	IO_OP;
	
	int n, k, d;
	cin >> n >> k >> d;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	dp[0] = 1;
	int l = 0;
	for(int i=1;i<=n;i++) {
		while(i-l >= k) {
			if(a[i]-a[l+1] <= d && dp[l]) {
				dp[i] = 1;
				break;
			}
			l++;
		}
	}
	if(dp[n]) cout << "YES" << endl;
	else cout << "NO" << endl;

}