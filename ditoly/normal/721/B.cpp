#include<cstdio>
#include<cstring>
#define MAX 100
char s[MAX+5][MAX+5],p[MAX+5];
int main()
{
	int n,k,i,pl,t=0,e=-1;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	scanf("%s",p);pl=strlen(p);
	for(i=0;i<n;i++)
	{
		if(strlen(s[i])<pl)t++;
		if(strlen(s[i])==pl)e++;
	}
	printf("%d %d",t+t/k*5+1,t+e+(t+e)/k*5+1);
}