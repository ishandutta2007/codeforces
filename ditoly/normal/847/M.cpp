#include<cstdio>
int main()
{
	int n,i,x,y,d,u=0;
	scanf("%d",&n);
	scanf("%d%d",&x,&y);d=y-x;
	for(i=2;i<n;++i)
	{
		scanf("%d",&x);
		if(x!=y+d)u=1;
		y=x;
	}
	printf("%d",u?y:y+d); 
}