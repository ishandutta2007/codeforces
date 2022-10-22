#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
const int inf = 1e9;
int j = (1 << 18);
int t[(1 << 19)][(1 << 5)][2];
int n, m, q, c, k; 
vector <int> a;
void add(int poz, int w, int ile)
{
	poz += j;
	t[poz][w][0] = t[poz][w][1] = ile;
	poz /= 2;
	while(poz)
	{
		t[poz][w][0] = min(t[poz * 2][w][0], t[poz * 2 + 1][w][0]);
		t[poz][w][1] = max(t[poz * 2][w][1], t[poz * 2 + 1][w][1]);
		poz /= 2;
	}
}
void ustaw(int poz, vector <int> &v)
{
	for(int i = 0; (1 << k) > i; ++i)
	{
		int sum = 0;
		for(int g = 0; k > g; ++g)
		{
			if((1 << g) & i)
				sum += v[g];
			else
				sum -= v[g];
		}
		add(poz, i, sum);
	}
}
pair<int, int> daj(int node, int lewo, int prawo, int x, int y, int w)
{
	if(y >= prawo && lewo >= x)
	{
		return mp(t[node][w][0], t[node][w][1]);
	}
	int mid = (lewo + prawo) / 2;
	pair <int, int> ans = mp(inf, -inf);
	if(x <= mid)
		ans = daj(2 * node, lewo, mid, x, y, w);
	if(y > mid)
	{
		pair <int, int> xd = daj(2 * node + 1, mid + 1, prawo, x, y, w);
		ans.fi = min(ans.fi, xd.fi);
		ans.se = max(ans.se, xd.se);
	}
	return ans;
}
int main(){
	for(int i = 1; 2 * j - 1 >= i; ++i)
	{
		for(int g = 0; 32 > g; ++g)
		{
			t[i][g][0] = inf;
			t[i][g][1] = -inf;
		}
	}
	scanf("%d %d", &n, &k);
	for(int i = 1; n >= i; ++i)
	{
		a.clear();
		for(int g = 1; k >= g; ++g)
		{
			scanf("%d", &c);
			a.pb(c);
		}
		ustaw(i, a);
	}
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &c);
		if(c == 1)
		{
			int gdzie, b;
			scanf("%d", &gdzie);
			a.clear();
			for(int g = 1; k >= g; ++g)
				scanf("%d", &b), a.pb(b);
			ustaw(gdzie, a);
		}
		else
		{
			int l, r;
			scanf("%d %d", &l, &r);
			int e = -inf;
			for(int g = 0; (1 << k) > g; ++g)
			{
				pair<int ,int> wynik = daj(1, 0, j - 1, l, r, g);
				e = max(e, wynik.se - wynik.fi);
			}
			printf("%d\n", e);
		}
	}
  return 0;
}