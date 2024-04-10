#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
const int nax = 500005, inf = 1e9;
int n, tab[nax], m;
vector <pair <int, int> > q[nax];
int j = (1 << 19);
pair <int, int> t[nax * 4];
int last[nax];
int ans[nax];
void add(int poz, int val)
{
	poz += j;
	t[poz] = {val, poz - j};
	poz /= 2;
	while(poz)
	{
		t[poz] = min(t[2 * poz], t[2 * poz + 1]);
		poz /= 2;
	}
}
pair <int, int> daj(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo && lewo >= x)
		return t[node];
	pair <int, int> w = {inf, inf};
	int mid = (lewo + prawo) / 2;
	if(mid >= x)
		w = daj(2 * node, lewo, mid, x, y);
	if(y > mid)
		w = min(w, daj(2 * node + 1, mid + 1, prawo, x, y));
	return w;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> tab[i];
	}
	for(int i = 1; 2 * j - 1 >= i; ++i)
		t[i] = {inf, inf};
	cin >> m;
	for(int i = 1; m >= i; ++i)
	{
		int a, b;
		cin >> a >> b;
		q[b].pb({a, i});
	}
	for(int i = 1; n >= i; ++i)
	{
		add(last[tab[i]], inf);
		add(i, last[tab[i]]);
		for(auto it: q[i])
		{
			pair <int, int> ja = daj(1, 0, j - 1, it.fi, i);
			if(ja.fi >= it.fi)
				ans[it.se] = 0;
			else
				ans[it.se] = ja.se;
		}
		last[tab[i]] = i;
	}
	for(int i = 1; m >= i; ++i)
		cout << tab[ans[i]] << " ";
	
	
	
	
	return 0;
}