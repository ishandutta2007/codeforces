#include<cstdio>

int ans[(1<<25)+10];
int q,num;
int main()
{
	ans[3]=1;
	ans[7]=1;
	ans[15]=5;
	ans[31]=1;
	ans[63]=21;
	ans[127]=1;
	ans[255]=85;
	ans[511]=73;
	ans[1023]=341;
	ans[2047]=89;
	ans[4095]=1365;
	ans[8191]=1;
	ans[16383]=5461;
	ans[32767]=4681;
	ans[65535]=21845;
	ans[131071]=1;
	ans[262143]=87381;
	ans[524287]=1;
	ans[1048575]=349525;
	ans[2097151]=299593;
	ans[4194303]=1398101;
	ans[8388607]=178481;
	ans[16777215]=5592405;
	ans[33554431]=1082401;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&num);
		if (ans[num]){printf("%d\n",ans[num]);continue;}
		int pos;
		for (pos=2;(1<<pos)-1<num;pos++);
		printf("%d\n",(1<<pos)-1);
	}
	return 0;
}