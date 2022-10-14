#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
const int M = 1e6 + 10;

int n;
int a[N];

int solve(int l, int r)
{
	if(l > r) return 0;
	if(l == r) return min(a[l], 1);
	int mn = 2e9;
	for (int i = l; i <= r; i ++)
	{
		mn = min(mn, a[i]);
	}
	for (int i = l; i <= r; i ++)
		a[i] -= mn;
	int last = l - 1;
	int res = mn;
	for (int i = l; i <= r; i ++)
	{
		if(a[i] == 0)
		{
			res += solve(last + 1, i - 1);
			last = i;
		}
	}
	res += solve(last + 1, r);
	res = min(r - l + 1, res);
	return res;
} 

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	printf("%d\n", solve(1, n));
}