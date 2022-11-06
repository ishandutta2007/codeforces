#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;
int tot, arr[1005], diff[15], p1, p2, n, x, y, res, ans, cnt;  
inline void query()
{
	if (!tot)
		return; 
	printf("? %d ", tot);
	for (int i = 0; i < tot; i++)
		printf("%d%c", arr[i] + 1, " \n"[i + 1 == tot]);
	fflush(stdout); 
#ifdef ONLINE_JUDGE
	scanf("%d", &res); 
#else
	cnt++; 
	res = 0; 
	for (int i = 0; i < tot; i++)
	{
		if (arr[i] == p1 - 1 || arr[i] == p2 - 1)
			res ^= y; 
		else
			res ^= x; 
	}
	printf("%d\n", res);
#endif
}
inline void output(int a, int b)
{
	if (a > b)
		swap(a, b); 
	printf("! %d %d\n", a + 1, b + 1);
	fflush(stdout); 
#ifndef ONLINE_JUDGE
	printf("%d queries\n", cnt);
	if (a != p1 - 1 || b != p2 - 1)
		printf("Wrong Answer\n");
	else
		printf("Correct\n");
#endif
	exit(0); 
}
void work(vector<int> pos)
{
	if (pos.size() == 1)
	{
		ans = pos[0]; 
		return; 
	}
	vector<int> v1, v2; 
	tot = 0; 
	for (int i = 0; i < pos.size(); i++)
	{
		if (i < pos.size() >> 1)
		{
			arr[tot++] = pos[i]; 
			v1.pb(pos[i]); 
		}
		else
			v2.pb(pos[i]); 
	}
	query(); 
	if (res == y || res == (x ^ y))
		work(v1); 
	else
		work(v2); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("835E.in", "r", stdin); 
#endif
	scanf("%d%d%d", &n, &x, &y); 
#ifndef ONLINE_JUDGE
	scanf("%d%d", &p1, &p2); 
#endif
	bool flg = false; 
	for (int i = 0; i < 10; i++)
	{
		vector<int> v1, v2; 
		tot = 0; 
		for (int j = 0; j < n; j++)
		{
			if (j & (1 << i))
			{
				v1.pb(j); 
				arr[tot++] = j; 
			}
			else
				v2.pb(j); 
		}
		query(); 
		if (tot && (res == y || res == (x ^ y)))
		{
			diff[i] = true; 
			if (!flg)
			{
				work(v1); 
				flg = true; 
			}
		}
	}
	int ans2 = ans; 
	for (int i = 0; i < 10; i++)
	{
		if (diff[i])
			ans2 ^= 1 << i; 
	}
	output(ans, ans2);
	return 0; 
}