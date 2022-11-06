#include <iostream>
#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
int n, k, arr[100005]; 
inline void init()
{
	scanf("%d%d", &n, &k); 
#ifndef ONLINE_JUDGE
	for (int i = 0; i < k; i++)
		scanf("%d", arr + i); 
#endif
}
inline bool query(int x, int y)
{
	if (x == -1 || y == -1)
		return false; 
#ifdef ONLINE_JUDGE
	printf("1 %d %d\n", x, y); 
	fflush(stdout); 
	char str[5]; 
	scanf("%s", str); 
	return str[0] == 'T'; 
#else
	int mnx = 1e9, mny = 1e9; 
	for (int i = 0; i < k; i++)
	{
		if (my_abs(x - arr[i]) < mnx)
			mnx = my_abs(x - arr[i]); 
	}
	for (int i = 0; i < k; i++)
	{
		if (my_abs(y - arr[i]) < mny)
			mny = my_abs(y - arr[i]); 
	}
	return mnx <= mny; 
#endif
}
inline int work(int l, int r)
{
	if (l > r)
		return -1; 
	while (l < r)
	{
		int m = l + r >> 1; 
		if (query(m, m + 1))
			r = m; 
		else
			l = m + 1; 
	}
	return l; 
}
inline void print(int x, int y)
{
	printf("2 %d %d\n", x, y); 
	fflush(stdout); 
#ifndef ONLINE_JUDGE
	int cnt = 0; 
	for (int i = 0; i < k; i++)
		cnt += x == arr[i] || y == arr[i]; 
	printf("%s\n", cnt == 2 ? "Correct" : "Wrong Answer");
#endif
}
int main()
{
	// freopen("809B.in", "r", stdin); 
	init(); 
	int x = work(1, n); 
	int y = work(1, x - 1); 
	if (!query(y, x))
		y = work(x + 1, n); 
	print(x, y); 
	return 0; 
}