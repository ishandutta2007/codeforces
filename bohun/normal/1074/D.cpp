#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int q;
int t, a, b;
int c, last;
unordered_map <int , int > par, ed;
void daj(int x)
{
	if(par.find(x) == par.end())
	{
		par[x] = x;
		ed[x] = 0;
	}
}
int Find(int x)
{
	int s = ed[x];
	int id = par[x];
	if(par[x] != x)
		par[x] = Find(par[x]);
	ed[x] = (s ^ ed[id]);
	return par[x];
}
void Union(int x, int y, int val)
{
	int nowy = (val ^ ed[x] ^ ed[y]);
	x = Find(x);
	y = Find(y);
	par[x] = y;
	ed[x] = nowy;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> q;
	while(q--)
	{
		cin >> t;
		if(last == -1)
			last = 1;
		if(t == 1)
		{
			cin >> a >> b >> c;
			a ^= last;
			b ^= last;
			c ^= last;
			if(a > b)
				swap(a, b);
			b++;
			daj(a);
			daj(b);
			if(Find(a) != Find(b))
				Union(a, b, c);
		}
		else
		{
			cin >> a >> b;
			a ^= last;
			b ^= last;
			if(a > b)
				swap(a, b);
			b++;
			daj(a);
			daj(b);
			int ans = 0;
			if(Find(a) == Find(b))
				ans = (ed[a] ^ ed[b]);
			else
				ans = -1;
			cout << ans << endl;
			last = ans;
		}
	}
			
			
	return 0;
}