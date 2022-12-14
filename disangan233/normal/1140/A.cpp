#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define mid ((l+r)>>1)
char qwq;
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    re cz=0,ioi=1;qwq=getch();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getch();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getch();
    return cz ak ioi;
}
int n,a[100005],ans;
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read();
	re i=1;
	while(i<=n)
	{
		re maxn=a[i];
		while(i!=maxn&&i<=n) i++,maxn=max(maxn,a[i]);
		i++;ans++;
	}
	cout<<ans<<endl;
}