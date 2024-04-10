#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m;
const int nax = 1000005;
char s[nax];
struct Node
{
	int zero, one, up, down, lazy;
	Node () {}
	Node (int a, int b, int c, int d)
	{
		zero = a;
		one = b;
		up = c;
		down = d;
		lazy = 0;
	}
};
Node t[2100005];
void akt(int node)
{
	t[node].zero = t[2 * node].zero + t[2 * node + 1].zero;
	t[node].one = t[2 * node].one + t[2 * node + 1].one;
	t[node].up = max(t[2 * node].zero + t[2 * node + 1].up, t[2 * node].up + t[2 * node + 1].one);
	t[node].down = max(t[2 * node].one + t[2 * node + 1].down, t[2 * node].down + t[2 * node + 1].zero);
}
void obroc(int node)
{
	swap(t[node].zero, t[node].one);
	swap(t[node].up, t[node].down);
}
void push(int node)
{
	if(t[node].lazy)
		{
			obroc(2 * node);
			obroc(2 * node + 1);
			t[2 * node].lazy ^= 1;
			t[2 * node + 1].lazy ^= 1;
			t[node].lazy = 0;
		}
}
			
int j = (1 << 20);
void daj(int node, int lewo, int prawo, int x, int y)
{
	if(y >= prawo and lewo >= x)
	{
		obroc(node);
		t[node].lazy ^= 1;
		return ;
	}
	int mid = (lewo + prawo) / 2;
	push(node);
	if(mid >= x)
		daj(2 * node, lewo, mid, x, y);
	if(y > mid)
		daj(2 * node + 1, mid + 1, prawo, x, y);
	akt(node);
}
int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; n >= i; ++i)
	{
		if(s[i] == '4')
			t[i + j] = Node(1, 0, 1, 1);
		else
			t[i + j] = Node(0, 1, 1, 1);
	}
	for(int i = j - 1; i >= 1; --i)
		akt(i);
	for(int i = 1; m >= i; ++i)
	{
		char d[10];
		scanf("%s", d + 1);
		if(d[1] == 'c')
			cout << t[1].up << endl;
		else
		{
			int a, b;
			scanf("%d %d", &a, &b);
			daj(1, 0, j - 1, a, b);
		}
	}
		
				
	return 0;
}