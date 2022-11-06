#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int arr[200005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("939C.in", "r", stdin); 
#endif
	int n, f, s; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		arr[i + n] = arr[i]; 
	}
	scanf("%d%d", &f, &s); 
	for (int i = 1; i < n << 1; i++)
		arr[i] += arr[i - 1]; 
	int ans = -1, pos; 
	for (int i = 0; i < n; i++)
	{
		int t = (f + n - i - 1) % n; 
		if (!t)
			t += n; 
		if (arr[i + s - f] - arr[i] > ans || (arr[i + s - f] - arr[i] == ans && t < pos))
		{
			ans = arr[i + s - f] - arr[i]; 
			pos = t; 
		}
	}
	printf("%d\n", pos);
	return 0; 
}