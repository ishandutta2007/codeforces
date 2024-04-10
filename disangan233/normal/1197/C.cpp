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
inline int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=3e5+5;
int a[N],b[N],n,k;
ll ans;
int main()
{
	n=read();k=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=1;i<n;i++) b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	for(re i=1;i<=n-k;i++) ans+=b[i];
	cout<<ans<<endl;
}