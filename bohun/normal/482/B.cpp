#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, q;
const int nax = 100005, nae = (1 << 18) + 100;
ll t[nax][3];
int seg[nae][30];
ll lazy[nae];
int j = (1 << 17);
void ustaw(int node, int val)
{
	for(int i = 0; 30 > i; ++i)
		if((1 << i) & val)
			seg[node][i] = 1;
	lazy[node] |= val;
}	
void add(int node, int lewo, int prawo, int x, int y, int val)
{
	if(y >= prawo and lewo >= x)
	{
		ustaw(node, val);
		return ;
	}
	int mid = (lewo + prawo) / 2;
	if(mid >= x)
		add(2 * node, lewo, mid, x, y, val);
	if(y > mid)
		add(2 * node + 1, mid + 1, prawo, x, y, val);
}
ll daj(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo and lewo >= x)
	{
		ll ans = 0;
		for(int i = 0; 30 > i; ++i)
			ans += (1 << i) * seg[node][i];
		return ans;
	}
	ll ans = (1LL << 31) - 1;
	int mid = (lewo + prawo) / 2;
	if(mid >= x)
		ans = (ans & daj(2 * node, lewo, mid, x, y));
	if(y > mid)
		ans = (ans & daj(2 * node + 1, mid + 1, prawo, x, y));
	return ans;
}
int main()
{	
	scanf("%d %d", &n, &q);
	for(int i = 1; q >= i; ++i)
		scanf("%lld %lld %lld", &t[i][0], &t[i][1], &t[i][2]);
	for(int i = 1; q >= i; ++i)
		add(1, 0, j - 1, t[i][0], t[i][1], t[i][2]);
	for(int i = 1; j > i; ++i)
		{
			ustaw(2 * i, lazy[i]);
			ustaw(2 * i + 1, lazy[i]);
			lazy[2 * i] |= lazy[i];
			lazy[2 * i + 1] |= lazy[i];
		}
	for(int i = j - 1; i >= 1; i--)
		{
			for(int g = 0; 30 > g; ++g)
				seg[i][g] = (seg[2 * i][g] & seg[2 * i + 1][g]);
		}
	for(int i = 1; q >= i; ++i)
		{
			if(daj(1, 0, j - 1, t[i][0], t[i][1]) != t[i][2])
				{
					cout << "NO";
					return 0;
				}
		}
	cout << "YES\n";
	for(int i = 1; n >= i; ++i)
		cout << daj(1, 0, j - 1, i, i) << " ";
		
}