#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int inf = 1e9, nax = 55;

int n;
int v[nax][10005];
vector <int> c[nax];


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int m;
	cin >> n >> m
	;
	for(int i = 1; n >= i; ++i)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int a;
			cin >> a;
			v[i][a] = 1;
			c[i].pb(a);
		}
	}
	
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 1; n >= j; ++j)
		{
			if(i == j)
				continue;
			int ile = 0;
			for(auto it: c[i])
			{
				if(v[j][it])
					++ile;
			}
			if(ile == 0)
			{
				cout << "impossible";
				return 0;
			}
		}
	}
	cout << "possible";
	
	
	
		
		
		
	
    return 0;
}