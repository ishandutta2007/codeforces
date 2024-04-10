#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

const int nax = 100005, mod = 1e9 + 7, inf = 1e9;
int n, q, a;
int t[500005];
int j = (1 << 17);
int lazy[500005];
int tab[nax];
char d;
void init(int x){
	for(int i = 1; x >= i; ++i)
	{
		lazy[i] = -1;
		t[i] = 2;
	}
}
void go(int node, int co)
{
	if(co <= 1)
	{
		t[node] = lazy[node] = co;
		return;
	}
	if(co == 3)
	{
		if(t[node] <= 1)
		{
			t[node] = lazy[node] = !t[node];
			return;
		}
		if(t[node] == 2)
		{
			t[node] = lazy[node] = 3;
			return;
		}
		if(t[node] == 3)
		{
			t[node] = 2;
			lazy[node] = -1;
			return;
		}
	}
	return;
}
void push(int node)
{
	if(lazy[node] == -1)
		return;
	go(2 * node, lazy[node]);
	go(2 * node + 1, lazy[node]);
	lazy[node] = -1;
	t[node] = 2;
	return;
}
		
		
		
		
		
void ustaw(int node, int lewo, int prawo, int x, int y, int co)
{
	if(y >= prawo && lewo >= x){
		go(node, co);
		return;
	}
	int mid = (lewo + prawo) / 2;
	push(node);
	if(x <= mid)
		ustaw(2 * node, lewo, mid, x, y, co);
	if(y > mid)
		ustaw(2 * node + 1, mid + 1, prawo, x, y, co);
}
int val(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo && lewo >= x)
		return t[node];
	push(node);
	int mid = (lewo + prawo) / 2;
	if(x <= mid)
		return val(2 * node, lewo, mid, x, y);
	else
		return val(2 * node + 1, mid + 1, prawo, x, y);
}
	

		
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	init(2 * j - 1);
	scanf("%d %d", &n, &q);
	for(int i = 1; n >= i; ++i)
	{
		scanf("%d", &tab[i]);
	}
	for(int i = 1; q >= i; ++i)
	{
		scanf(" %c %d", &d, &a);
		if(d == '>')
		{
			if(a >= 0)
			{
				ustaw(1, 0, j - 1, a + 1, j - 1, 0);
			}
			else
			{
				ustaw(1, 0, j - 1, -a, j - 1, 0);
				ustaw(1, 0, j - 1, 0, -a - 1, 3);
			}
		}
		else
		{
			if(a > 0)
			{
				ustaw(1, 0, j - 1, a, j - 1, 1);
				ustaw(1, 0, j - 1, 0, a - 1, 3);
			}
			else
			{
				ustaw(1, 0, j - 1, -a + 1, j - 1, 1);
			}
		}
	}
	for(int i = 1; n >= i; ++i)
	{
		int b = val(1, 0, j - 1, abs(tab[i]), abs(tab[i]));
		int x = tab[i];
		int y = -tab[i];
		if(b == 0)
			printf("%d ", min(x, y));
		if(b == 1)
			printf("%d ", max(x, y));
		if(b == 2)
			printf("%d ", tab[i]);
		if(b == 3)
			printf("%d ", -tab[i]);
	}
	
		
	
			
	return 0;
}