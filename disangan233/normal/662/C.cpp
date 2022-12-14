#include<bits/stdc++.h>
using namespace std;
#define in inline
#define re register int
#define db double
#define ll long long
#define ak *
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
#define int ll
const int p=1e9+7,N=(1<<20)+1;
int n,m,len,g[N],cnt[N],a[N],b[N],w1[N],w2[N];
char s[100005];
in void fwt(re *a,re op)
{
	for(re i=1;i<len;i<<=1) for(re j=0;j<len;j++)
	if(i&j)
	{
		re x=a[j-i],y=a[j];
		a[j-i]=(x+y),a[j]=(x-y);
	}
	if(op==-1) for(re i=0;i<len;i++) a[i]/=(1<<n);
}
in void sxor(re *a,re *b,re *c)
{
	for(re i=0;i<len;i++) w1[i]=a[i],w2[i]=b[i];
	fwt(w1,1),fwt(w2,1);
	for(re i=0;i<len;i++) w1[i]=1ll*w1[i]*w2[i];
	fwt(w1,-1);
	for(re i=0;i<len;i++) c[i]=w1[i];
}
signed main()
{
	n=read();m=read();len=1<<n;
	for(re i=0;i<n;i++)
	{
		scanf("%s",s);
		for(re j=0;j<m;j++)
		if(s[j]=='1') g[j]|=(1<<i);
	}
	for(re i=0;i<m;i++) a[g[i]]++;
	for(re i=1;i<len;i++) cnt[i]=cnt[i>>1]+(i&1);
	for(re i=0;i<len;i++) b[i]=min(cnt[i],n-cnt[i]);
	sxor(a,b,a);
	re ans=1e9;
	for(re i=0;i<len;i++) ans=min(ans,a[i]);
	cout<<ans<<endl;
	return 0;
}