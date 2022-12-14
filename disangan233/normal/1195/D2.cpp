#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=1e5+5,p=998244353;
ll n,a[N][15],cnt[15],len[N],mxt,ans;
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	{
		re x=read();
		while(x) a[i][++len[i]]=x%10,x/=10;
		cnt[len[i]]++;mxt=max(cnt[len[i]],mxt);
	}

	for(re i=1;i<=n;i++)
	for(re j=1;j<=10;j++)
	{
		ll nw=0;
		if(len[i]>=j)
		{
			ll mul=1;
			for(re k=1;k<=j;k++)
			nw=(nw+mul*a[i][k]%p)%p,mul=mul*100%p;
			for(re k=j+1;k<=len[i];k++)
			nw=(nw+mul*a[i][k]%p),mul=mul*10%p;
		}
		else
		{
			ll mul=1;
			for(re k=1;k<=len[i];k++)
			nw=(nw+mul*a[i][k]%p),mul=mul*100%p;
		}
		ans=(ans+nw*cnt[j]%p)%p;
	}
	for(re i=1;i<=n;i++)
	for(re j=1;j<=10;j++)
	{
		ll nw=0;
		if(len[i]>=j)
		{
			ll mul=10;
			for(re k=1;k<=j;k++)
			{
				nw=(nw+mul*a[i][k]%p)%p;
				if(j==k) mul=mul*10%p;
				else mul=mul*100%p;
			}
			for(re k=j+1;k<=len[i];k++)
			nw=(nw+mul*a[i][k]%p),mul=mul*10%p;
		}
		else
		{
			ll mul=10;
			for(re k=1;k<=len[i];k++)
			nw=(nw+mul*a[i][k]%p),mul=mul*100%p;
		}
		ans=(ans+nw*cnt[j]%p)%p;
	}
	cout<<ans<<endl;
}