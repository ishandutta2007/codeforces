#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll com[120001][101];
ll imos[102][100001];
int main()
{
	com[0][0] = 1;
	for (int i = 1; i <= 120000; i++)
	{
		com[i][0] = 1;
		for (int j = 1; j <= 100; j++)com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % mod;
	}
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num; i++)scanf("%I64d", &imos[0][i]);
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		imos[zc + 1][za]++;
		for (int j = 0; j <= zc; j++)imos[zc + 1 - j][zb + 1] += mod - com[zb - za + j][j];
	}
	for (int i = 101; i >= 1; i--)
	{
		for (int j = 0; j < num; j++)imos[i][j + 1] += imos[i][j];
		for (int j = 0; j <= num; j++)imos[i - 1][j] = (imos[i - 1][j] + imos[i][j]) % mod;
	}
	for (int i = 0; i < num; i++)printf("%I64d ", imos[0][i]);
	printf("\n");
}