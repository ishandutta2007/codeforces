#include<stdio.h>
#include<algorithm>
using namespace std;

typedef __int64 LL;

LL cnt[200009];
LL num[200009];
LL ans;

int main()
{
	int n, q, i, l, r;
	LL run, ans;

	scanf("%d%d", &n, &q);
	for(i = 0; i < n; i++)
		scanf("%I64d", &num[i]);
	sort(num, num+n);

	while(q--)
	{
		scanf("%d%d",&l,&r);
		l--;
		r--;
		cnt[l]++;
		cnt[r+1]--;
	}

	run = 0;
	for(i = 0; i < n; i++)
	{
		run += cnt[i];
		cnt[i] = run;
	}

	sort(cnt, cnt+n);

	ans = 0;
	for(i = 0; i < n; i++)
		ans += cnt[i]*num[i];

	printf("%I64d\n", ans);

	return 0;
}