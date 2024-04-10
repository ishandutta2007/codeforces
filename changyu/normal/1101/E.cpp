#include<cstdio>
int m,x,y,xx,xy;char o[2];
int main()
{
	int t;
	scanf("%d",&m);
	for(;m--;){
	  scanf("%s%d%d",o,&x,&y);
	  if(x<y)t=x,x=y,y=t;
	  if(o[0]=='+')xx=x>xx?x:xx,xy=y>xy?y:xy;
	  else puts(xx<=x&&xy<=y?"YES":"NO");
	}return 0;
}