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
int arr[100005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("938B.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i); 
	arr[0] = 1; 
	arr[n + 1] = 1e6; 
	int ans = 1e9; 
	for (int i = 0; i <= n; i++)
		ans = std::min(ans, std::max(arr[i] - 1, 1000000 - arr[i + 1])); 
	printf("%d\n", ans);
	return 0; 
}