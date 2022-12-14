#include<bits/stdc++.h>
using namespace std;
#define re register int
#define db double
#define ll long long
#define in inline
#define ak *
in char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
in ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
int n,m;
char s[100005];
int x[100005],y[100005],ans[100005];
in void add(int *x, int *y)
{
	x[0]=max(x[0], y[0]);
	for(re i=1;i<=x[0];i++)
	x[i]+=y[i],x[i+1]+=x[i]/10,x[i]%=10;
	while (x[x[0]+1]) ++x[0];
	return;
}
in int cmp(int*x,int*y)
{
	if(x[0]!=y[0]) return x[0]<y[0];
	for(re i=x[0];i;--i) if(x[i]<y[i])
	return 1;
	else if(x[i]>y[i]) return 0;
	return 0;
}
int main()
{
	cin>>n;scanf("%s",s+1);
	ans[0]=n+1;
	for(re i=(n+2)>>1;i>1;i--)
	{
		if(s[i]!='0')
		{
			x[0]=i-1,y[0]=n-i+1;
			for(re j=1;j<i;j++) x[j]=s[i-j]-'0';
			for(re j=i;j<=n;j++) y[j-i+1]=s[n-j+i]-'0';
			for(re j=x[0]+1;j<=n;j++) x[j]=0;
			for(re j=y[0]+1;j<=n;j++) y[j]=0;
			add(x,y);
			if(cmp(x,ans)) for(re j=0;j<=x[0];j++) ans[j]=x[j];
			break;
		}
	}
	for(re i=(n+3)>>1;i<=n;i++)
	{
		if(s[i]!='0')
		{
			x[0]=i-1,y[0]=n-i+1;
			for(re j=1;j<i;j++) x[j]=s[i-j]-'0';
			for(re j=i;j<=n;j++) y[j-i+1]=s[n-j+i]-'0';
			for(re j=x[0]+1;j<=n;j++) x[j]=0;
			for(re j=y[0]+1;j<=n;j++) y[j]=0;
			add(x,y);
			if(cmp(x,ans)) for(re j=0;j<=x[0];j++) ans[j]=x[j];
			break;
		}
	}
	for(re i=ans[0];i;i--) putchar(ans[i]+'0');
}