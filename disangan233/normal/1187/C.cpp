#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
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
int tot,n,m,ans[1005],col[1005];
struct did{
	int op,l,r;
	bool operator <(did x) const {return r>x.r;}
}a[1005];
int main()
{
	n=read();m=read();
	for(re i=1;i<=m;i++) a[i]=(did){read(),read(),read()};
	sort(a+1,a+m+1);
	for(re i=1;i<=m;i++)
	if(a[i].op)
	{
		if(col[a[i].r])
		{
			for(re j=a[i].l;j<=a[i].r;j++) col[j]=col[a[i].r];
		}
		else{
			tot++;
			for(re j=a[i].l;j<=a[i].r;j++) col[j]=tot;
		}
	}
	ans[n]=tot=1;
	for(re i=n-1;i;i--)
	{
		if(col[i]!=col[i+1]||!col[i]) ans[i]=++tot;
		else ans[i]=ans[i+1];
	}
	for(re i=1;i<=m;i++)
	if(!a[i].op)
	{
		re ok=0;
		for(re j=a[i].l;j<a[i].r;j++)
		if(ans[j]>ans[j+1]) {ok=1;break;}
		if(!ok) return puts("NO"),0;
	}
	puts("YES");
	for(re i=1;i<=n;i++) cout<<ans[i]<<" ";
}