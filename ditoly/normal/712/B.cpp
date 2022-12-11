#include<cstdio>
#define MAXL 100000
#define abs(x) (x<0?-x:x)
char s[MAXL+5];
int main()
{
	int i,x=0,y=0;
	scanf("%s",s);
	for(i=0;s[i];i++)
	{
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		if(s[i]=='U')y--;
		if(s[i]=='D')y++;
	}
	x=abs(x)+abs(y);
	printf("%d",(x&1)?-1:x>>1);
}