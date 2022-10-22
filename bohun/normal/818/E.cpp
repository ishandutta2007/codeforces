#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k;
int t[100005];
int fak[100005][30];
int ja[30], on[30];
vector < pair < int, int > > v;
vector < pair < int, int > > p(int x)
{
	vector < pair < int, int > > ans ;
	for(ll i = 2; x >= i * i; ++i)
		{
			int ile = 0;
			while(x % i == 0)
			{
				ile++;
				x /= i;
			}
			if(ile)
				ans.pb({i, ile});
		}
	if(x > 1)
		ans.pb({x, 1});
	return ans;
}
bool ok()
{
	for(int i = 0; 20 > i; ++i)
		if(on[i] < ja[i])
			return 0;
	return 1;
}
void dodaj(int id, int val)
{
	for(int i = 0; 20 > i; ++i)
		on[i] += fak[id][i] * val;
}
int main()
{	
	scanf("%d %d", &n ,&k);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	if(k == 1)
	{
		cout << (ll) n * (n + 1) / 2;
		return 0;
	}
	v = p(k);
	for(int i = 0; ss(v) > i; ++i)
		ja[i] = v[i].se;
	for(int i = 1; n >= i; ++i)
		for(int j = 0; ss(v) > j; ++j)
			{
				int ile = 0;
				int x = t[i];
				while(x % v[j].fi == 0)
					{
						ile++;
						x /= v[j].fi;
					}
				fak[i][j] = ile;
			}
	ll res = 0;
	int kon = 1;
	for(int i = 1; n >= i; ++i)
	{
		while(kon <= n and ok() == 0)
			dodaj(kon++, 1);
		if(ok())
			res += n - kon + 2;
		dodaj(i, -1);
	}
	printf("%lld \n", res);
		
}