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

ll a[100005], dp0[100005], dp1[100005], dp2[100005];

int main()
{
	IO_OP;
	
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	for(int i=0;i<n;i++) 
		cin >> a[i];
	dp0[0] = p * a[0];
	for(int i=1;i<n;i++)
		dp0[i] = max(dp0[i-1], p*a[i]);
	dp1[0] = dp0[0] + q * a[0];
	for(int i=1;i<n;i++)
		dp1[i] = max(dp1[i-1], dp0[i] + q * a[i]);
	dp2[0] = dp1[0] + r * a[0];
	for(int i=1;i<n;i++)
		dp2[i] = max(dp2[i-1], dp1[i] + r * a[i]);
	cout << dp2[n-1] << endl;
}