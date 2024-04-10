#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dat[201010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num + num; i++)scanf("%I64d", &dat[i]);
	sort(dat, dat + num + num);
	ll mini = (dat[num - 1] - dat[0])*(dat[num + num - 1] - dat[num]);
	for (int i = 0; i <= num; i++)mini = min(mini, (dat[i + num - 1] - dat[i])*(dat[num + num - 1] - dat[0]));
	printf("%I64d\n", mini);
}