#include<cstdio>
inline int abs(int x){return x<0?-x:x;}
int main()
{
	int a,b,c,i,p,ans=-1;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=100;i++)
	{
		p=abs(a-i)+abs(b-i)+abs(c-i);
		if(ans<0||p<ans)ans=p;
	}
	printf("%d\n",ans);
}