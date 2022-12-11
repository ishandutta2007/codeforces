#include<cstdio>
#define MAX 100
char f[MAX+5][MAX+5],mx[MAX+5]; 
int main()
{
	int n,m,i,j,ans=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",&f[i]);
		for(j=0;j<m;j++)if(f[i][j]>mx[j])mx[j]=f[i][j]; 
	}
	for(i=0;i<n;i++)for(j=0;j<m;j++)
		if(f[i][j]==mx[j]){ans++;break;}
	printf("%d",ans); 
}