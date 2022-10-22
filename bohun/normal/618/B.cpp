#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int res[55], ile[55];
bool jest = 0;
int main()
{	
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, t[55][55];
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		for(int c = 1; n >= c; ++c)
			ile[c] = 0;
		for(int j = 1; n >= j; ++j)
		{
			cin >> t[i][j];
			ile[t[i][j]]++;
		}
		bool ok = 0;
		for(int c = 1; n >= c; ++c)
			if(ile[c] >= 2)
			{
				res[i] = c;
				ok = 1;
				break;
			}
		if(!ok && jest == 0)
		{
			res[i] = n - 1;
			jest = 1;
		}
		else if(!ok)
			res[i] = n;
	}
	for(int i = 1; n >= i; ++i)
		cout << res[i] << " ";
		
	
	
	
	return 0;
}