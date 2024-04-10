#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 500005, mod = 998244353;
const ll inf = 1e18;

int p[nax];
int ile[nax];

int t[nax];

int Find(int x)
{
	if(x != p[x])
		p[x] = Find(p[x]);
	return p[x];
}
void Onion(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x == y)
		return ;
	ile[x] += ile[y];
	p[y] = x;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		p[i] = i;
		ile[i] = 1;
	}
	for(int i = 1; m >= i; ++i)
	{
		int k = 0;
		cin >> k;
		int first = -1;
		for(int j = 1; k >= j; ++j)
		{
			int a;
			cin >> a;
			if(j == 1)
				first = a;
			else
				Onion(first, a);
		}
	}
	for(int i = 1; n >= i; ++i)
		cout << ile[Find(i)] << " ";
	
	
		
		
		
	
    return 0;
}