#include<cstdio>
int main()
{
	int n,m,i,o=0;char c;
	scanf("%d%d",&n,&m);
	while(n--)for(i=0;i<m;i++)for(;;)
	{
		c=getchar();
		if(c=='C'||c=='M'||c=='Y'){o=1;break;}
		if(c=='W'||c=='G'||c=='B')break;
	}
	printf(o?"#Color":"#Black&White");
}