#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
inline int read()
{
    re cz=0,ioi=1;
    qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
char c[6]={'a','e','i','o','u'};
int n;
int main()
{
    n=read();
    for(re x=5;x<=n;x++)
    {
        if(n%x==0&&n/x>=5) 
        {
            for(re i=1;i<=n/x;i++)
            for(re j=1;j<=x;j++)
            {
                putchar(c[(i+j)%5]);
         	}
         	return 0;
        }
    }
 	return puts("-1"),0;
}