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

const int INF = 1e9 + 7;

int a[300005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[n-i-1];
	for(int i=1;i<n;i++)
		a[i] += a[i-1];
	int ans = a[n-1];
	sort(a, a+n-1, greater<int>());
	for(int i=0;i<k-1;i++)
		ans += a[i];
	
	cout << ans << endl;
}