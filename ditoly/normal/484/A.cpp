#include<cstdio>
#include<cstring>
int main()
{
	int n,lz[60],lzn,rzn,i,j;long long l,r,rz[60],ans;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d",&l,&r);
		memset(lz,0,sizeof(lz));
		for(lzn=0;l;l>>=1)lz[lzn++]=l&1;
		for(rzn=0;r;r>>=1)rz[rzn++]=r&1;
		for(ans=0,i=rzn;i--;)if(lz[i]==rz[i])ans|=rz[i]<<i;else break;
		if(i>=0)
		{
			for(j=0;j<=i;++j)if(!rz[j])break;
			ans+=(1LL<<i+1)-1-(j<=i?1LL<<i:0);
		}
		printf("%I64d\n",ans);
	}
}