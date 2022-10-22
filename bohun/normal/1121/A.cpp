#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
using namespace std;
int n , m, c;
int a[10005], b[10005];
vector < int > v[1000];
bool ok[1005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> c;
	for(int i = 1; n >= i; ++i)
		cin >> a[i];
	for(int i = 1; n >= i; ++i)
	{
		int aa;
		cin >> aa;
		b[i] = aa;
		v[aa].pb(i);
	}
	for(int i = 1; 100 >= i; ++i)
		sort(v[i].begin(),v[i].end());
	
	int ans = 0;
	for(int i = 1; c >=i ;++i)
	{
		int aa;
		cin >> aa;
		for(auto it: v[b[aa]])
		{
			if(a[it] > a[aa] and ok[it] == 0)
			{
				ans ++;
				ok[aa] = 1;
				break ;
			}
		}
	}
	cout << ans;
				
	return 0;
}