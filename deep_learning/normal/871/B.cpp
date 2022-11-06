#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
using namespace std; 
typedef long long ll; 
int x[5005], y[5005], pos[5005], arr[5005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("871B.in", "r", stdin); 
#endif
	int n, cnt = 0, lst; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("? %d 0\n", i);
		fflush(stdout); 
		scanf("%d", x + i); 
		pos[x[i]] = i; 
	}
	for (int i = 0; i < n; i++)
	{
		printf("? %d %d\n", pos[0], i);
		fflush(stdout); 
		scanf("%d", y + i); 
	}
	for (int i = 0; i < n; i++)
	{
		memset(arr, -1, sizeof(arr)); 
		for (int j = 0; j < n; j++)
			arr[i ^ x[j]] = j; 
		bool f = true; 
		for (int j = 0; j < n && f; j++)
			f &= arr[j] == (y[j] ^ i); 
		if (f)
		{
			cnt++; 
			lst = i; 
		}
	}
	printf("!\n%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d%c", x[i] ^ lst, " \n"[i + 1 == n]);
	fflush(stdout); 
	return 0; 
}