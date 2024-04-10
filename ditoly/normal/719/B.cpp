#include<cstdio>
#define MAXN 100000
char s[MAXN+5];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int main()
{
	int n,r1,b1,r2,b2,i;
	scanf("%d%s",&n,s);
	r1=b1=r2=b2=0;
	for(i=0;i<n;i++)
	{
		if(i&1)
		{
			if(s[i]=='r')b1++;
			else r2++;
		}
		else
		{
			if(s[i]=='b')r1++;
			else b2++;
		}
	}
	printf("%d",min(max(r1,b1),max(r2,b2)));
}