#include<cstdio>
int main()
{
	int a,b,c,i,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	for(scanf("%d",&i);i--;)scanf("%d",&a),a>b&&a<c?++ans:0;
	printf("%d",ans); 
}