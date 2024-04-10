#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
int t[100005];
int p[(1 << 18) + 9][20];
int j = (1 << 17);
int lazy[(1 << 18) + 9];
ll ans = 0;
void rob(int node)
{
	for(int i = 0; 20 > i; ++i)
		p[node][i] = p[node * 2][i] + p[node * 2 + 1][i];
}
void build()
{
	for(int i = j - 1; i >= 1; --i)
		rob(i);
}
void akt(int node, int val, int len)
{
	for(int i = 0; 20 > i; ++i)
		{
			if((1 << i) & val)
				p[node][i] = len - p[node][i];
		}
		lazy[node] ^= val;
}
void push(int node, int len)
{
	akt(2 * node, lazy[node], len / 2);
	akt(2 * node + 1, lazy[node], len / 2);
	lazy[node] = 0;
}
void add(int node, int lewo, int prawo, int x, int y, int val)
{
	if(y >= prawo and lewo >= x)
		{
			akt(node, val, prawo - lewo + 1);
			return ;
		}
	int mid = (lewo + prawo) / 2;
	if(lazy[node] != 0)
		push(node, prawo - lewo + 1);
	if(mid >= x)
		add(2 * node, lewo, mid, x, y, val);
	if(y > mid)
		add(2 * node + 1, mid + 1, prawo, x, y, val);
	rob(node);
}
void licz(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo and lewo >= x)
	{
		for(int i = 0; 20 > i; ++i)
			ans += (ll)(1 << i) * p[node][i];
		return ;
	}
	int mid = (lewo + prawo) / 2;
	push(node, prawo - lewo + 1);
	if(mid >= x)
		licz(2 * node, lewo, mid, x, y);
	if(y > mid)
		licz(2 * node + 1, mid + 1, prawo, x, y);
}
int main()
{	
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	for(int i = 1; n >= i; ++i)
		for(int g = 0; 20 > g; ++g)
			if((1 << g) & t[i])
				p[j + i][g] = 1;
	build();
	int m;
	scanf("%d", &m);
	for(int i = 1; m >= i; ++i)
	{
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if(t == 1)
		{
			ans = 0;
			licz(1, 0, j - 1, l, r);
			printf("%lld\n", ans);
		}
		else
		{
			int x;
			scanf("%d", &x);
			add(1, 0, j - 1, l, r, x);
		}
	}
	
		
	
}