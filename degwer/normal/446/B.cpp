#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll map[1000][1000];
ll g[2][1000001];
int gen;
int pr;
void calc(int mx, int my,int t)
{
	priority_queue<ll>que;
	for (int i = 0; i < mx; i++)
	{
		ll t = 0;
		for (int j = 0; j < my; j++)t += map[i][j];
		que.push(t);
	}
	ll now = 0;
	for (int i = 0; i <= gen; i++)
	{
		g[t][i] = now;
		ll a = que.top();
		que.pop();
		now += a;
		que.push(a - my*pr);
	}
}
int main()
{
	int mx, my;
	scanf("%d%d%d%d", &mx, &my, &gen, &pr);
	for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)scanf("%I64d", &map[i][j]);
	calc(mx, my, 0);
	for (int i = 0; i < 1000; i++)for (int j = i + 1; j < 1000; j++)swap(map[i][j], map[j][i]);
	calc(my, mx, 1);
	for (int i = 0; i < 1000; i++)for (int j = i + 1; j < 1000; j++)swap(map[i][j], map[j][i]);
	ll maxi = -1000000000000000000LL;
	for (int i = 0; i <= gen; i++)
	{
		maxi = max(maxi, g[0][i] + g[1][gen - i] - (ll)i*(ll)(gen - i)*pr);
	}
	printf("%I64d\n", maxi);
}