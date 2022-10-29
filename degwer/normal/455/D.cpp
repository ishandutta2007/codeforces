#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
#define B 320
#define NB 320
deque<int>deq[NB];
int dat[NB][100010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		deq[i / B].push_back(z);
		dat[i / B][z]++;
	}
	int query;
	scanf("%d", &query);
	int last = 0;
	for (int p = 0; p < query; p++)
	{
		//for (int i = 0; i < num; i++)printf("%d ", deq[i / B][i%B]); printf("\n");
		int z;
		scanf("%d", &z);
		if (z == 1)
		{
			int lb, ub;
			scanf("%d%d", &lb, &ub);
			lb = (lb + last - 1) % num + 1, ub = (ub + last - 1) % num + 1;
			lb--, ub--;
			if (ub < lb)swap(lb, ub);
			if (lb / B == ub / B)
			{
				int a = lb%B, b = ub%B;
				int x = lb / B;
				int t = deq[x][b];
				for (int i = b; i >= a + 1; i--)deq[x][i] = deq[x][i - 1];
				deq[x][a] = t;
			}
			else
			{
				int s = lb / B, t = ub / B;
				int a = lb%B, b = ub%B;
				int now = deq[t][b];
				dat[t][now]--;
				for (int i = b; i >= 1; i--)deq[t][i] = deq[t][i - 1];
				deq[t].pop_front();
				for (int i = t - 1; i >= s + 1; i--)
				{
					int x = deq[i][deq[i].size() - 1];
					deq[i].pop_back();
					deq[i + 1].push_front(x);
					dat[i][x]--;
					dat[i + 1][x]++;
				}
				int x = deq[s][deq[s].size() - 1];
				deq[s + 1].push_front(x);
				dat[s][x]--;
				dat[s + 1][x]++;
				for (int i = deq[s].size() - 1; i >= a + 1; i--)deq[s][i] = deq[s][i - 1];
				deq[s][a] = now;
				dat[s][now]++;
			}
		}
		else
		{
			int lb, ub, kai;
			scanf("%d%d%d", &lb, &ub, &kai);
			lb = (lb + last - 1) % num + 1, ub = (ub + last - 1) % num + 1, kai = (kai + last - 1) % num + 1;
			lb--, ub--;
			if (ub < lb)swap(lb, ub);
			int ans = 0;
			if (lb / B == ub / B)
			{
				int a = lb%B, b = ub%B;
				int x = lb / B;
				for (int i = b; i >= a; i--)if (deq[x][i] == kai)ans++;
			}
			else
			{
				int s = lb / B, t = ub / B;
				int a = lb%B, b = ub%B;
				for (int i = b; i >= 0; i--)if (deq[t][i] == kai)ans++;
				for (int i = t - 1; i >= s + 1; i--)ans += dat[i][kai];
				for (int i = deq[s].size() - 1; i >= a; i--)if (deq[s][i] == kai)ans++;
			}
			printf("%d\n", ans);
			last = ans;
		}
	}
}