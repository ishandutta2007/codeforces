#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[55];
int siz[55];
vector<int>pat[55];
vector<int>ko[55];
double dp[55][55];
double com[115][115];
void dfs(int node)
{
	flag[node] = true;
	siz[node] = 0;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (flag[pat[node][i]])continue;
		dfs(pat[node][i]);
		ko[node].push_back(pat[node][i]);
		siz[node] += siz[pat[node][i]] + 1;
	}
	//printf("node %d:\n", node + 1);
	for (int p = 0; p <= siz[node]; p++)
	{
		int nows = 0;
		double pdp[2][55];
		for (int i = 0; i <= p; i++)pdp[0][i] = pdp[1][i] = 0;
		int cur = 0;
		pdp[0][0] = 1.0;
		for (int i = 0; i < ko[node].size(); i++)
		{
			//printf("%d:\n", i);
			double rui[55];
			rui[0] = 0;
			for (int j = 0; j <= p; j++)rui[j + 1] = rui[j] + dp[ko[node][i]][j];
			for (int j = 0; j <= p; j++)
			{
				int rema = p - j, remb = siz[node] - nows - rema;
				if (rema < 0 || remb < 0)continue;
				for (int k = 0; k <= p - j; k++)
				{
					int taka = k, takb = siz[ko[node][i]] + 1 - k;
					if (taka < 0 || takb < 0 || rema < taka || remb < takb)continue;
					double kak = com[rema][taka] / com[rema + remb][taka + takb] * com[remb][takb];
					double ex = 0;
					if (taka > 0)ex += double(taka) / double(taka + takb)*rui[taka] / taka / 2.0;
					if (takb > 0)ex += double(takb) / double(taka + takb)*dp[ko[node][i]][taka];
					//printf("%d %d %d %d %lf %lf\n", taka, takb, rema, remb,kak,ex);
					pdp[1 - cur][j + k] += pdp[cur][j] * kak*ex;
				}
			}
			for (int j = 0; j <= p; j++)pdp[cur][j] = 0;
			//for (int j = 0; j <= p; j++)printf("%lf ", pdp[1 - cur][j]); printf("\n");
			cur = 1 - cur;
			nows += siz[ko[node][i]] + 1;
		}
		dp[node][p] = pdp[cur][p];
		//printf("***%lf\n", dp[node][p]);
	}
	//printf("\n");
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb), pat[zb].push_back(za);
	}
	for (int i = 0; i <= 110; i++)
	{
		com[i][0] = 1;
		for (int j = 1; j <= i; j++)com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
	}
	for (int p = 0; p < num; p++)
	{
		for (int i = 0; i < num; i++)flag[i] = false, siz[i] = 0, ko[i].clear();
		for (int i = 0; i <= num; i++)for (int j = 0; j <= num; j++)dp[i][j] = 0;
		//printf("%d-----\n", p + 1);
		dfs(p);
		printf("%.10lf\n", dp[p][num - 1]);
	}
}