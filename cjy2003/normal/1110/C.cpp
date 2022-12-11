#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
int ans[1<<25],now;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int query(int x)
{
	int s=0;
	for(int i=1;i<x;++i)
		s=max(s,gcd(x&i,x^i));
	return s;
}
int main()
{
	scanf("%d",&q);
	ans[33554431]=1082401;
	ans[16777215]=5592405;
	ans[8388607]=178481;
	ans[4194303]=1398101;
	ans[2097151]=299593;
	ans[1048575]=349525;
	ans[524287]=1;
	ans[262143]=87381;
	ans[131071]=1;
	ans[65535]=21845;
	ans[32767]=4681;
	ans[16383]=5461;
	ans[8191]=1;
	ans[4095]=1365;
	ans[2047]=89;
	ans[1023]=341;
	ans[511]=73;
	ans[255]=85;
	ans[127]=1;
	ans[63]=21;
	ans[31]=1;
	ans[15]=5;
	ans[7]=1;
	ans[3]=1;
	for(int i=(1<<25)-1;i>=2;--i)
	{
		if(ans[i])now=i;
		else ans[i]=now;
	}
	while(q--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}