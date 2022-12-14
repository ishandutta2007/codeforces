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
inline ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
ll m,n,a[55][10005];
int main()
{
    m=read(),n=read();
    for(re i=1;i<=m;i++)
    {
        re k=read();
        for(re j=1;j<=k;j++) a[i][read()]=1;
    }
    for(re i=1;i<=m;i++)
    for(re j=i+1;j<=m;j++)
    {
        re can=1;
        for(re k=1;k<=n;k++)
        {
            if(!a[i][k]) continue;
            if(!a[j][k]) continue;
            if(a[i][k]&&a[j][k]) {can=0;break;}
        }
        if(can) return puts("impossible"),0;
    }
    puts("possible");
}