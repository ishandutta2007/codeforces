#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int n;
int seg[(1 << 20) + 9];
vector < int > lazy[(1 << 20) + 9];
ll t[100005][3];
vector < ll > v;
map < ll , int > m;
void czysc(int node)
{
	if((int)lazy[node].size() >= 2)
	{
		int s = (int)lazy[node].size();
		while(s >= 2 and lazy[node][s - 1] == 2 and lazy[node][s - 2] == 2)
		{
			lazy[node].pop_back();
			lazy[node].pop_back();
			s -= 2;
		}
		while(s >= 2 and (lazy[node][s - 1] == 0 or lazy[node][s - 1] == 1))
		{
			int k = lazy[node][s - 1];
			lazy[node].clear();
			lazy[node].pb(k);
			s = 1;
		}
	}
}
		
void ustaw(int node, int co)
{
	if(co == 0 or co == 1)
		{
			seg[node] = co;
			lazy[node].pb(co);
		}
	else
		{
			if(seg[node] == 1)
				seg[node] = 0;
			else if(seg[node] == 0)
				seg[node] = 1;
			else
				seg[node] = 2;
			lazy[node].pb(2);
		}
	czysc(node);
}
void push(int node)
{
	if(lazy[node].empty())
		return;
	for(auto it: lazy[node])
		{
			ustaw(2 * node, it);
			ustaw(2 * node + 1, it);
		}
	lazy[node].clear();
}
void akt(int node)
{
	if(seg[2 * node] == 1 and seg[2 * node + 1] == 1)
		seg[node] = 1;
	else if(seg[2 * node] == 0 and seg[2 * node + 1] == 0)
		seg[node] = 0;
	else
		seg[node] = 2;
}
void fun(int node, int co)
{
	if(co == 0 or co == 1)
		{
			seg[node] = co;
		}
	else
		{
			seg[node] ^= 1;
		}
}
void add(int node, int lewo, int prawo, int x, int y, int co)
{
	if(y >= prawo and lewo >= x)
		{
			if(lewo == prawo)
				fun(node, co);
			else
				ustaw(node, co);
			return ;
		}
	int mid = (lewo + prawo) / 2;
	push(node);
	if(mid >= x)
		add(2 * node, lewo, mid, x, y, co);
	if(y > mid)
		add(2 * node + 1, mid + 1, prawo, x, y, co);
	akt(node);
}
ll daj(int node, int lewo, int prawo)
{
	if(lewo == prawo)
		return v[lewo];
	int mid = (lewo + prawo) / 2;
	push(node);
	ll w = -1;
	if(seg[2 * node] != 1)
		w = daj(2 * node, lewo, mid);
	else
		w = daj(2 * node + 1, mid + 1, prawo);
	akt(node);
	return w;
}
int main()
{	
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
	{
		scanf("%lld %lld %lld", &t[i][0], &t[i][1], &t[i][2]);
		if(t[i][0] == 3)
			t[i][0] = 2;
		else if(t[i][0] == 2)
			t[i][0] = 0;
		v.pb(t[i][1]);
		v.pb(t[i][2] + 1);
		v.pb(t[i][2]);
	}
	v.pb(1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int j = 0; (int)v.size() > j; ++j)
		m[v[j]] = j;
	for(int i = 1; (1 << 20) > i; ++i)
		 seg[i] = 0;
	for(int i = 1; n >= i; ++i)
	{
		add(1, 0, (1 << 19)  - 1, m[t[i][1]], m[t[i][2]], t[i][0]);
		printf("%lld\n",  daj(1, 0, (1 << 19) - 1));
	} 
	
	return 0;
}