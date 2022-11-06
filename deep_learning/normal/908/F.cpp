#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
using namespace std; 
typedef long long ll; 
int pos[300005]; 
char tp[300005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908F.in", "r", stdin); 
#endif
	int n, g = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c", pos + i, tp + i); 
		g += tp[i] == 'G'; 
	}
	if (!g)
	{
		int ans = 0, l = 1e9, r = 0; 
		for (int i = 0; i < n; i++)
		{
			if (tp[i] == 'R')
			{
				l = min(l, pos[i]); 
				r = max(r, pos[i]); 
			}
		}
		ans += max(r - l, 0); 
		l = 1e9;
		r = 0; 
		for (int i = 0; i < n; i++)
		{
			if (tp[i] == 'B')
			{
				l = min(l, pos[i]); 
				r = max(r, pos[i]); 
			}
		}
		ans += max(r - l, 0); 
		printf("%d\n", ans);
		return 0; 
	}
	ll ans = 0; 
	for (int i = -1, j; i < n; i = j + 1)
	{
		j = i; 
		while (j < n && tp[j] != 'G')
			j++; 
		if (i == -1)
		{
			int a = 1e9, b = 1e9; 
			for (int k = 0; k < j; k++)
			{
				if (tp[k] == 'R')
					a = min(a, pos[k]); 
				if (tp[k] == 'B')
					b = min(b, pos[k]); 
			}
			ans += max(pos[j] - a, 0) + max(pos[j] - b, 0); 
		}
		else if (j == n)
		{
			int a = 0, b = 0; 
			for (int k = i; k < n; k++)
			{
				if (tp[k] == 'R')
					a = max(a, pos[k]); 
				if (tp[k] == 'B')
					b = max(b, pos[k]); 
			}
			ans += max(a - pos[i - 1], 0) + max(b - pos[i - 1], 0); 
		}
		else
		{
			int la = pos[i - 1], lb = pos[i - 1], ra = 0, rb = 0; 
			for (int k = i; k < j; k++)
			{
				if (tp[k] == 'R')
				{
					ra = max(ra, pos[k] - la); 
					la = pos[k]; 
				}
				if (tp[k] == 'B')
				{
					rb = max(rb, pos[k] - lb); 
					lb = pos[k]; 
				}
			}
			ra = max(ra, pos[j] - la); 
			rb = max(rb, pos[j] - lb); 
			ans += min((ll)3 * (pos[j] - pos[i - 1]) - ra - rb, (ll)2 * (pos[j] - pos[i - 1])); 
		}
	}
	printf("%lld\n", ans);
	return 0; 
}