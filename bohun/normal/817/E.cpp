#include <bits/stdc++.h>
using namespace std;
struct Node{
	Node *idz[2];
	int sum;
	Node()
	{
		idz[0] = idz[1] = NULL;
		sum = 0;
	}
};
Node tab[1];
int ans = 0;
void rob(Node *node)
{
	for(int i = 0; 2 > i; ++i)
		if(!node->idz[i])
			node->idz[i] = new Node();
}
void add(Node *node, int bit, int val, int num)
{
	node->sum += val;
	if(num < 0)
		return ;
	int b = ((1 << num) & bit);
	if(b)
		b = 1;
	rob(node);
	add(node->idz[b], bit, val, num - 1);
}
void go(Node *node, int p, int l, int num)
{
	if(num < 0)
		return;
	int prawo = (((1 << num) & l) > 0);
	int lewo = (((1 << num) & p) > 0);
	rob(node);
	if(prawo)
		ans += node->idz[lewo]->sum;
	go(node->idz[(lewo ^ prawo)], p, l, num - 1);
}
	
int main()
{	
	int n;
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
	{
		int t, p;
		scanf("%d %d", &t, &p);
		if(t == 1)
			add(tab, p, 1, 29);
		else if(t == 2)
			add(tab, p, -1, 29);
		else
		{
			ans = 0;
			int l;
			scanf("%d", &l);
			go(tab, p, l, 29);
			printf("%d\n", ans);
		}
	}
}