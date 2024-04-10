#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define mp make_pair
#define pb push_back
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
int ans[35]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("848A.in", "r", stdin); 
#endif
	int n, tot = 0; 
	scanf("%d", &n); 
	if (!n)
	{
		printf("a\n");
		return 0; 
	}
	for (int i = 1000; i >= 2 && n;)
	{
		if (n >= i * (i - 1) / 2)
		{
			ans[tot++] = i;
			n -= i * (i - 1) / 2; 
		}
		else
			i--; 
	}
	for (int i = 0; i < tot; i++)
	{
		while (ans[i]--)
			printf("%c", i + 'a');
	}
	printf("\n");
	return 0; 
}