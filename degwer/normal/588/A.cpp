#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int ret = 0;
	int m = 10000;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		m = min(m, zb);
		ret += m*za;
	}
	printf("%d\n", ret);
}