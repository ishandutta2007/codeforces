#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
inline ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
in void mid(re x,re y)
{
	for(re i=1;i<=x;i++) 
	printf("%d %d\n",y,i);
} 
in void side(re x,re &y,re z)
{
	for(re i=2;i<=(x<<1)&&y;i+=2)
	printf("%d %d\n",z,i),y--;
}
int main()
{
	re t=read();
	while(t--)
	{
		re m=read(),n=read();
		if(n-1>3*m||m-1>3*n) puts("NO");
		else
		{
			puts("YES");
			if(n==m) mid(m<<1,1);
			else if(n<m) 
			{
				mid(n<<1|1,2);m-=n+1;
				side(n,m,1);side(n,m,3);
			}
			else
			{
				mid(m<<1|1,3);n-=m+1;
				side(m,n,2);side(m,n,4); 
			}
		}
	}
}