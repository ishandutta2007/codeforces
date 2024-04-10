#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, q;
char s[100005];
int a, b, c;
int j = (1 << 17);
int t[(1 << 18) + 6][26];
int lazy[(1 << 18) + 6][26];
void push(int node, int len, int id)
{
	if(lazy[node][id] != -1)
	{
		t[2 * node][id] = t[2 * node + 1][id] = len / 2 * lazy[node][id];
		lazy[2 * node][id] = lazy[2 * node + 1][id] = lazy[node][id];
		lazy[node][id] = -1;
	}
}
void ustaw(int node, int lewo, int prawo, int x, int y, int ile, int id)
{
	if(y >= prawo and lewo >= x)
	{
		t[node][id] = ile * (prawo - lewo + 1);
		lazy[node][id] = ile;
		return ;
	}
	int mid = (lewo + prawo) / 2;
	push(node, prawo - lewo + 1, id);
	if(mid >= x)
		ustaw(2 * node, lewo, mid, x, y, ile, id);
	if(y > mid)
		ustaw(2 * node + 1, mid + 1, prawo, x, y, ile, id);
	t[node][id] = t[2 * node][id] + t[2 * node + 1][id];
}
int sum(int node, int lewo, int prawo, int x, int y, int id)
{
	if(y >= prawo and lewo >= x)
		return t[node][id];
	int mid = (lewo + prawo) / 2;
	push(node, prawo - lewo + 1, id);
	int ans = 0;
	if(mid >= x)
		ans += sum(2 * node, lewo, mid, x, y, id);
	if(y > mid)
		ans += sum(2 * node + 1, mid + 1, prawo, x, y, id);
	return ans;
}
int main()
{
	scanf("%d %d", &n, &q);
	scanf("%s", s + 1);
	for(int i = 1; j > i; ++i)
		for(int g = 0; 26 > g; ++g)
			lazy[i][g] = -1;
	for(int i = 1; n >= i; ++i)
		ustaw(1, 0, j - 1, i, i, 1, s[i] - 'a'); 
	for(int g = 1; q >= g; ++g)
	{
		scanf("%d %d %d", &a , &b, &c);
		if(c == 0)
		{
			int last = a - 1; 
			for(int i = 25; i >= 0; --i)
			{
				int ile = sum(1, 0, j - 1, a, b, i);
				if(ile)
					{
						ustaw(1, 0, j - 1, a, b, 0, i);
						ustaw(1, 0, j - 1, last + 1, last + ile, 1, i);
						last = last + ile;
					}
			}
		}
		else
		{
			int last = a - 1; 
			for(int i = 0; 25 >= i; ++i)
			{
				int ile = sum(1, 0, j - 1, a, b, i);
				if(ile)
					{
						ustaw(1, 0, j - 1, a, b, 0, i);
						ustaw(1, 0, j - 1, last + 1, last + ile, 1, i);
						last = last + ile;
					}
			}
		}
	}
	for(int i = 1; n >= i; ++i)
		for(int g = 0; 25 >= g; ++g)
			{
				if(sum(1, 0, j - 1, i, i, g))
					{
						cout << (char) ('a' + g);
					}
			}
			 
						 
	return 0;
}