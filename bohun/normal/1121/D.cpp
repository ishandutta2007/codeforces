#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
using namespace std;
int n, k, m, s;	
int t[500005];
int licz[500005];
int w = 0;
int d[500005];
void odp(int lewo ,int prawo)
{
	int res = max(prawo - lewo + 1 - k, 0) + (lewo - 1) % k;
	cout << res <<endl;
	int g = prawo - lewo + 1 - k;
	for(int i = lewo; prawo >= i; ++i)
	{
		if(d[t[i]] > 0)
		{
			d[t[i]]--;
		}
		else if(g > 0)
			{
				cout << i << " ";
				g--;
			}	
	}
	for(int i = 1; (lewo - 1) % k >= i; ++i)	
		cout << i << " ";
	exit(0);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> m >> k >> n >> s;
	for(int i = 1; m >= i; ++i)
	{
		cin >> t[i];
	}
	for(int i = 1; s >= i; ++i)
	{
		int a;
		cin >> a;
		d[a]++;
	}
	w = -s;
	int siz = m - k * n;
	int kon = 0;
	for(int i = 1; m >= i; ++i)
	{
		while(w != 0 and kon <= m)
		{
			kon++;
			licz[t[kon]]++;
			if(licz[t[kon]] <= d[t[kon]])
				w++;
		}
		int dl = kon - i + 1;
		int nad = dl - k;
		
		if(w == 0 and (i - 1) % k + nad <= siz)
			odp(i, kon);
		licz[t[i]]--;
		if(licz[t[i]] < d[t[i]])
			w--;
	}
	cout << -1;
			
		
	return 0;
}