#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n, k, sum;
string x;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> x;
	for(int i = 0; n > i; ++i)
		{
			int p = x[i] - 'a';
			sum += max(p, 25 - p);
		}
	if(sum < k)
	{
		cout << -1;
		return 0;
	}
	for(int i = 0; n > i; ++i)
	{
		int p = x[i] - 'a';
		if(p > 25 - p)
		{
			cout << (char)('a' + p - min(k, p));
			k -= min(k, p);
		}
		else
		{
			cout << (char)('a' + p + min(25 - p, k));
			k -= min(25 - p, k);
		}
	}
	return 0;	
}