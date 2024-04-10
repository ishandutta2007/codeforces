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
#define gc() getch()
char qwq;
inline ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=3e5+5,mod=1e9+7;
int n,k,a[N];
int main()
{
	re t=read();
	while(t--)
	{
		n=read(),k=read();
		ll sum=0;
		for(re i=1;i<=n;i++) a[i]=read(),sum+=a[i]%2;
		if(sum>=k&&(sum&1)==(k&1))
		{
			puts("YES");
			for(re i=1;i<=n;i++)
			{
				if(k==1) {printf("%d\n",n);break;}
				if(a[i]%2) printf("%d ",i),k--;
			}
		}
		else puts("NO");
	}
}