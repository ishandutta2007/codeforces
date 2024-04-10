#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std; 
typedef long long ll; 
int x2, y2; 
pair<char, ll> near[8]; 
int check(int x, int y)
{
	if (x == x2 && y < y2)
		return 0; 
	if (x == x2 && y > y2)
		return 1; 
	if (y == y2 && x < x2)
		return 2; 
	if (y == y2 && x > x2)
		return 3; 
	if (x - x2 == y - y2 && x > x2)
		return 4; 
	if (x - x2 == y - y2 && x < x2)
		return 5; 
	if (x - x2 == y2 - y && x > x2)
		return 6; 
	if (x - x2 == y2 - y && x < x2)
		return 7; 
	return -1; 
}
ll dis(int x, int y, int x2, int y2)
{
	return (ll)labs(x - x2) + labs(y - y2); 
}
int main()
{
	// freopen("734D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	scanf("%d%d", &x2, &y2); 
	x2--; 
	y2--; 
	for (int i = 0; i < 8; i++)
		near[i].second = 1e18; 
	for (int i = 0; i < n; i++)
	{
		char c; 
		int x, y; 
		scanf("\n%c%d%d", &c, &x, &y); 
		x--; 
		y--;
		int res = check(x, y); 
		if (res != -1 && dis(x, y, x2, y2) < near[res].second)
		{
			near[res].first = c; 
			near[res].second = dis(x, y, x2, y2); 
		}
	}
	// for (int i = 0; i < 8; i++)
	// 	printf("%c %lld\n", near[i].first, near[i].second);
	for (int i = 0; i < 4; i++)
	{
		if (near[i].first == 'Q' || near[i].first == 'R')
		{
			printf("YES\n");
			return 0; 
		}
	}
	for (int i = 4; i < 8; i++)
	{
		if (near[i].first == 'Q' || near[i].first == 'B')
		{
			printf("YES\n");
			return 0; 
		}
	}
	printf("NO\n");
	return 0; 
}