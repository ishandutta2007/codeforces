#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500
char a[MN+5],b[MN+5],s[10];
bool query(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y';
}
int main()
{
	int n,x,y,i;
	n=read();
	for(i=x=y=1;i<n;++i)
		if(query(x,y+1,n,n))a[i]='R',++y;else a[i]='D',++x;
	for(i=x=y=n;--i;)
		if(query(1,1,x-1,y))b[i]='D',--x;else b[i]='R',--y;
	printf("! %s%s",a+1,b+1);
}