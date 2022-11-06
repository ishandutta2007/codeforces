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
int x[1005]; 
double y[1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908C.in", "r", stdin); 
#endif
	int n, r; 
	scanf("%d%d", &n, &r); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", x + i); 
		y[i] = r; 
		for (int j = 0; j < i; j++)
		{
			double a = 4 * r * r, b = (x[i] - x[j]) * (x[i] - x[j]); 
			if (r + r >= my_abs(x[i] - x[j]))
				y[i] = max(y[i], sqrt(a - b) + y[j]); 
		}
		printf("%.15lf%c", y[i], " \n"[i + 1 == n]);
	}
	return 0; 
}