#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
map<pii, int>ma;
int ans[100];
ll dfs(pii x)
{
	if (ma.count(x))return ma[x];
	int d[70];
	fill(d, d + 70, 0);
	for (ll i = 1; i <= x.second; i++)
	{
		if(!(x.first&(1LL<<i)))d[dfs(make_pair(x.first|(1LL << i), x.second - i))] = 1;
	}
	for (int i = 0; i < 70; i++)if (d[i] == 0)return ma[x] = i;
}
int main()
{
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 2;
	ans[4] = 2;
	ans[5] = 2;
	ans[6] = 3;
	ans[7] = 3;
	ans[8] = 3;
	ans[9] = 3;
	ans[10] = 4;
	ans[11] = 4;
	ans[12] = 4;
	ans[13] = 4;
	ans[14] = 4;
	ans[15] = 5;
	ans[16] = 5;
	ans[17] = 5;
	ans[18] = 5;
	ans[19] = 5;
	ans[20] = 5;
	ans[21] = 6;
	ans[22] = 6;
	ans[23] = 6;
	ans[24] = 6;
	ans[25] = 6;
	ans[26] = 6;
	ans[27] = 6;
	ans[28] = 7;
	ans[29] = 7;
	ans[30] = 7;
	ans[31] = 7;
	ans[32] = 7;
	ans[33] = 7;
	ans[34] = 7;
	ans[35] = 7;
	ans[36] = 8;
	ans[37] = 8;
	ans[38] = 8;
	ans[39] = 8;
	ans[40] = 8;
	ans[41] = 8;
	ans[42] = 8;
	ans[43] = 8;
	ans[44] = 8;
	ans[45] = 9;
	ans[46] = 9;
	ans[47] = 9;
	ans[48] = 9;
	ans[49] = 9;
	ans[50] = 9;
	ans[51] = 9;
	ans[52] = 9;
	ans[53] = 9;
	ans[54] = 9;
	ans[55] = 10;
	ans[56] = 10;
	ans[57] = 10;
	ans[58] = 10;
	ans[59] = 10;
	ans[60] = 10;
	int num;
	scanf("%d", &num);
	int x = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		x ^= ans[z];
	}
	if (x == 0)printf("YES\n");
	else printf("NO\n");
}