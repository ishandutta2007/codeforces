#include<bits/stdc++.h>
using namespace std;
#define re register int
#define in inline
#define db double
#define ll long long
#define ak *
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in ll read()
{
	ll cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=1e5+5;
ll n,m,k,a[N],c[N],ans;
map<ll,int>b;
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read(),b[a[i]]++;
	re op=0,cnt=0;
	if(b[0]>=2) return puts("cslnb"),0;
	for(re i=1;i<=n;i++)
	if(a[i]!=0)
	{
		if(b[a[i]]>=3) return puts("cslnb"),0;
		if(b[a[i]]==2)
		{
			cnt++;b[a[i]]=0;
			if(cnt>1) return puts("cslnb"),0;
			if(b[a[i]-1]) return puts("cslnb"),0;
		}
	}
	sort(a+1,a+n+1);
	for(re i=1;i<=n;i++) ans+=a[i]-(i-1);
	puts(ans%2?"sjfnb":"cslnb");
}