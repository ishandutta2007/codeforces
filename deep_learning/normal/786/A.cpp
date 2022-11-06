#include <iostream>
#include <cstdio>
using namespace std; 
char str[][10] = {"Loop", "Win", "Lose"}; 
int cnt[2], status[7005][2], deg[7005][2], num[2][7005], n;
void work(int pos, int cur)
{
	int nxt = cur ^ 1; 
	for (int i = 0; i < cnt[nxt]; i++)
	{
		int from = (pos - num[nxt][i] + n) % n; 
		if (status[from][nxt])
			continue; 
		if (status[pos][cur] == 2)
		{
			status[from][nxt] = 1; 
			work(from, nxt); 
		}
		else
		{
			if (!--deg[from][nxt])
			{
				status[from][nxt] = 2; 
				work(from, nxt); 
			}
		}
	}
}
int main()
{
	// freopen("786A.in", "r", stdin); 
	scanf("%d%d", &n, cnt); 
	for (int i = 0; i < cnt[0]; i++)
		scanf("%d", num[0] + i); 
	scanf("%d", cnt + 1); 
	for (int i = 0; i < cnt[1]; i++)
		scanf("%d", num[1] + i); 
	status[0][0] = status[0][1] = 2; 
	for (int i = 0; i < n; i++)
	{
		deg[i][0] = cnt[0]; 
		deg[i][1] = cnt[1]; 
	}
	work(0, 0); 
	work(0, 1); 
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%s%c", str[status[j][i]], " \n"[j + 1 == n]);
	}
	return 0; 
}