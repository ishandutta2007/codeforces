#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>
#define mp make_pair
using namespace std; 
pair<int, int> arr[1005], pencil[1005]; 
int main()
{
	// freopen("161B.in", "r", stdin); 
	int n, k, cnt = 0, p_cnt = 0; 
	scanf("%d%d", &n, &k); 
	double tot = 0; 
	for (int i = 0; i < n; i++)
	{
		int c, t; 
		scanf("%d%d", &c, &t); 
		tot += c; 
		if (!--t)
			arr[cnt++] = mp(c, i); 
		else
			pencil[p_cnt++] = mp(c, i); 
	}
	sort(arr, arr + cnt, greater<pair<int, int> >()); 
	sort(pencil, pencil + p_cnt, less<pair<int, int> >()); 
	if (cnt < k)
	{
		for (int i = 0; i < cnt; i++)
			tot -= (double)arr[i].first / 2; 
		printf("%.1lf\n", tot);
		for (int i = 0; i < cnt; i++)
			printf("1 %d\n", arr[i].second + 1);
		for (int i = cnt; i < k - 1; i++)
			printf("1 %d\n", pencil[--p_cnt].second + 1);
		printf("%d ", p_cnt);
		while (p_cnt--)
			printf("%d%c", pencil[p_cnt].second + 1, " \n"[!p_cnt]);
	}
	else
	{
		for (int i = 0; i < k - 1; i++)
			tot -= (double)arr[i].first / 2; 
		tot -= (double)min(arr[cnt - 1].first, p_cnt ? pencil[0].first : 1000000000) / 2; 
		printf("%.1lf\n", tot);
		for (int i = 0; i < k - 1; i++)
			printf("1 %d\n", arr[i].second + 1);
		printf("%d ", n - k + 1);
		for (int i = k - 1; i < cnt; i++)
			printf("%d ", arr[i].second + 1);
		for (int i = 0; i < p_cnt; i++)
			printf("%d ", pencil[i].second + 1);
		printf("\n");
	}
	return 0; 
}