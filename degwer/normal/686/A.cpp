#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	ll now;
	scanf("%d%I64d", &num, &now);
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		char za;
		int zb;
		scanf(" %c%d", &za, &zb);
		if (za == '+')
		{
			now += zb;
		}
		else
		{
			if (now >= zb)
			{
				now -= zb;
			}
			else cnt++;
		}
	}
	printf("%I64d %d\n", now, cnt);
}