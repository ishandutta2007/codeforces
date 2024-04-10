#include<cstdio>
typedef long long LL;
LL u,v,a1,a2,a3;
int main()
{
	scanf("%lld%lld",&u,&v);
	if(v<u){puts("-1");return 0;}
	if(u==v)
	{
		if(!u)puts("0");
		else printf("1\n%lld\n",u);
		return 0;
	}
	a1=u;v-=u;
	if(v&1){puts("-1");return 0;}
	for(int i=1;i<=60;++i)
	if((v>>i)&1)
	a2|=(1LL<<(i-1)),a3|=(1LL<<(i-1));
	if((a1&a2)==0)
	printf("2\n%lld %lld\n",(a1|a2),a3);
	else printf("3\n%lld %lld %lld\n",a1,a2,a3);
	return 0;
}