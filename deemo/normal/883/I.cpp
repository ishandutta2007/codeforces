
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 300003;

int n, k;
int a[N], dp[N], sum[N];

bool check(int x)
{
	int l = 0;
	dp[0] = sum[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		while(a[i] - a[l + 1] > x)
			l++;
		dp[i] = 0;
		if(i - l >= k)
			dp[i] = bool(sum[i - k] - sum[l] > 0) || dp[l];
		sum[i] = sum[i - 1] + dp[i];
	}
	return dp[n];
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		a[i] = in();
	sort(a + 1, a + n + 1);
	a[0] = -1e9 - 1;
	int L = - 1, R = 1e9;
	while(R - L > 1)
	{
		int mid = (L + R)/2;
		if(check(mid))
			R = mid;
		else
			L = mid;
	}
	cout << R << endl;
}