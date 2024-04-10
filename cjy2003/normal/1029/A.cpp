#include<stdio.h>
#include<string.h>
int n,k,nxt[51],len;
char a[51];
int main()
{
	scanf("%d %d %s",&n,&k,a);
	nxt[0]=-1;
	for(int i=1;i<=n;++i)
	{
		int j=nxt[i-1];
		while(j!=-1)
		{
			if(a[j]==a[i-1])
			{
				nxt[i]=j+1;	
				break;
			}
			else j=nxt[j];	
		}
		if(j==-1)nxt[i]=0;
	//	printf("%d ",nxt[i]);
	}
	printf("%s",a);
	len=n-nxt[n];
	for(int i=1;i<k;++i)
		for(int j=n-len;j<n;++j)
			printf("%c",a[j]);
	return 0;
}