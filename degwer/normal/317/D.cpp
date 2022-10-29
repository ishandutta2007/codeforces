#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//char dp[1 << 29];
//int use[29];
int gr[30];
typedef long long ll;
bool f[100000];
int main()
{
	/*for (int i = 0; i < 29; i++)
	{
		int x = (1 << 29) - 1;
		for (int j = i; j < 29; j += i + 1)x -= (1 << j);
		use[i] = x;
	}
	for (int p = 0; p < (1 << 29); p++)
	{
		if (0 == (p&((1 << 20) - 1)))printf("%d\n", p);
		int x[30];
		fill(x, x + 30, 0);
		for (int i = 0; i < 29; i++)
		{
			if (p&(1 << i))
			{
				x[dp[p&use[i]]] = 1;
			}
		}
		for (int i = 0; i < 30; i++)
		{
			if (x[i] == 0)
			{
				dp[p] = i;
				break;
			}
		}
	}
	for (int i = 0; i <= 29; i++)printf("gr[%d] = %d;\n", i, dp[(1 << i) - 1]);*/
	gr[0] = 0;
	gr[1] = 1;
	gr[2] = 2;
	gr[3] = 1;
	gr[4] = 4;
	gr[5] = 3;
	gr[6] = 2;
	gr[7] = 1;
	gr[8] = 5;
	gr[9] = 6;
	gr[10] = 2;
	gr[11] = 1;
	gr[12] = 8;
	gr[13] = 7;
	gr[14] = 5;
	gr[15] = 9;
	gr[16] = 8;
	gr[17] = 7;
	gr[18] = 3;
	gr[19] = 4;
	gr[20] = 7;
	gr[21] = 4;
	gr[22] = 2;
	gr[23] = 1;
	gr[24] = 10;
	gr[25] = 9;
	gr[26] = 3;
	gr[27] = 6;
	gr[28] = 11;
	gr[29] = 12;
	ll num;
	scanf("%I64d", &num);
	ll cnt = 0;
	int ans = 0;
	for (ll i = 2; i*i <= num; i++)
	{
		if (f[i])continue;
		int c = 0;
		ll now = i;
		for (;;)
		{
			if (now > num)break;
			c++;
			now *= i;
			if (now < 100000)f[now] = true;
		}
		cnt += c;
		ans ^= gr[c];
	}
	ans ^= (num - cnt) % 2;
	if (ans)printf("Vasya\n");
	else printf("Petya\n");
}