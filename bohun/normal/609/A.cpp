#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

int main()
{
	int n, m, a[105];
	cin >> n >> m ;
	for(int i = 1; n >= i; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	for(int i = n; i >= 1; --i)
	{
		if(sum + a[i] >= m)
		{
			cout << n - i + 1;
			return 0;
		}
		sum += a[i];
	}
	return 0;
}