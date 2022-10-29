#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
ld logkai[100001];
ld ans[601];
#define INF 1e99
ld lc(int a, int b)
{
	if (b<0 || b>a)return -INF;
	return logkai[a] - logkai[a - b] - logkai[b];
}
int main()
{
	int num, gen, kai;
	scanf("%d%d%d", &num, &gen, &kai);
	logkai[0] = 0;
	for (int i = 1; i <= 100000; i++)logkai[i] = logkai[i - 1] + log(i);
	ld logsum = lc(gen, kai);
	ld ret = 0;
	for (int i = num * 2; i >= 0; i--)
	{
		for (int j = 0; j <= num; j++)
		{
			int k = i - j;
			if (k<0 || k>num)continue;
			ld now = lc(num, k) + lc(num, j);
			now += lc(gen - num*num + (num - j)*(num - k), kai - (num*num - (num - j)*(num - k)));
			ans[i] += exp(now - logsum);
		}
		ret += ans[i];
	}
	if (ret >= INF)printf("%lf\n", INF);
	else printf("%.30lf\n", double(ret));
}