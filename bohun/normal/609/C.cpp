#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, a[100005];
int main()
{
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1; n >= i; ++i)
		scanf("%d", &a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	if(sum % n == 0)
	{
		int wynik = 0;
		for(int i = 1; n >= i; ++i)
		{
			wynik += max(0, a[i] - (sum / n));
		}
		cout << wynik;
		return 0;
	}
	int ile = sum - (sum / n) * n;
	int ans = 0;
	for(int i = 1; n >= i; ++i)
		ans += max(0, a[i] - (sum / n + (i >= n - ile + 1 ? 1 : 0 )));
	cout << ans;
	return 0;
}