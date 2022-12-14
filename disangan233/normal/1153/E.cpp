#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
int a,b,n;
inline int ask(re x,re y,re z,re zz)
{
	cout<<"? "<<x<<" "<<y<<" "<<z<<" "<<zz<<endl;
	fflush(stdout);
	return read()&1;
}
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	if(ask(i,1,i,n)==1)
	{
		if(!a) a=i;
		else {b=i;break;}
	}
	if(a)
	{
		re l=1,r=n;
		while(l<r)
		{
			re mid=(l+r)>>1;
			if(ask(a,l,a,mid)) r=mid;
			else l=mid+1;
		}
		re ans=l;l=1;r=n;
		while(l<r)
		{
			re mid=(l+r)>>1;
			if(ask(b,l,b,mid)) r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",a,ans,b,l);
		fflush(stdout);return 0;
	}
	for(re i=1;i<n;i++)
	if(ask(1,i,n,i)==1)
	{
		if(!a) a=i;
		else {b=i;break;}
	}
	if(!b) b=n;
	re l=1,r=n;
		while(l<r)
		{
			re mid=(l+r)>>1;
			if(ask(l,a,mid,a)) r=mid;
			else l=mid+1;
		}
		re ans=l;l=1;r=n;
		while(l<r)
		{
			re mid=(l+r)>>1;
			if(ask(l,b,mid,b)) r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",ans,a,l,b);
		fflush(stdout);return 0;
}