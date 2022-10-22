#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
using namespace std;
int n;
int a[300005];
int ile[300005];
int d[300005];
int ans = 0;	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> a[i], ile[a[i]]++;
	sort(a + 1, a + n + 1);
	for(int i = 2; 200000 >= i; ++i)
	{
		int opt = 0;
		for(int j = 1; n >= j; ++j)
		{
			if(i - a[j] > 0)
				{
					if(d[a[j]] != i and d[i - a[j]] != i and ile[i - a[j]] > 0 and a[j] + a[j] != i)
						{
							opt++;
							d[a[j]] = i;
							d[i - a[j]] = i;
						}
				}
		}
		ans = max(ans, opt);
	}
	cout << ans;
				
	return 0;
}