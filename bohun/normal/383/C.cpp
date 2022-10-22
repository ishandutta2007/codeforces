#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m, a, b;
const int nax = 200005;
vector < int > v[nax];
int c;
int tim = 0;
int pre[nax], out[nax], h[nax];
int j = (1 << 18);
int seg[(1 << 19) + 6][2];
int col[nax];
void go(int node, int prev)
{
	pre[node] = tim++;
	for(auto it: v[node])
		if(it != prev)
			{
				h[it] = 1 + h[node];
				go(it, node);
			}
	out[node] = tim - 1;
}
int daj(int node, int p)
{
	node += j;
	int ans = 0;
	while(node)
	{
		ans += seg[node][p];
		ans -= seg[node][(p ^ 1)];
		node /= 2;
	}
	return ans;
}
void add(int node, int lewo ,int prawo , int x, int y, int val, int p)
{
	if(y >= prawo && lewo >= x)
		{
			seg[node][p] += val;
			return ;
		}
	int mid = (lewo + prawo) / 2;
	if(mid >= x)
		add(2 * node, lewo, mid, x, y, val, p);
	if(y > mid)
		add(2 * node + 1, mid + 1, prawo, x, y, val, p);
}
int main()
{	
	scanf("%d %d", &n ,&m);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &col[i]);
	for(int i = 1; n > i; ++i)
		{
			scanf("%d %d", &a, &b);
			v[a].pb(b);
			v[b].pb(a);
		}
	go(1, -1);
	for(int i = 1; m >= i; ++i)
	{
		int t;
		scanf("%d %d", &t, &a);
		if(t == 2)
			printf("%d\n", daj(pre[a], h[a] % 2) + col[a]);
		else
			{
				scanf("%d", &b);
				add(1, 0, j - 1, pre[a], out[a], b, h[a] % 2);
			}
	}
}