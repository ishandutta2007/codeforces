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
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
int n;
struct did{
	int a,b;
	bool operator < (did x) const {return a!=x.a?a>x.a:b>x.b;}
}a[200005];
priority_queue<int>b;
map<int, int> mp, mp2;
int main()
{
	re t=read();
	while(t--)
	{
		mp.clear();
		n=read();re cnt=0;
		for(re i=1;i<=n;i++)
		{
			re x=read(),y=read();
			if(mp.find(x)!=mp.end())
			{
				re id=mp[x];
				a[id].a++,a[id].b+=y;
			}
			else
			mp[x]=cnt,a[cnt++]=(did){1,y};
		}
		sort(a,a+cnt);while(!b.empty()) b.pop();
		re ans=0,sum=0,top=1e9;
		for(re i=0;i<cnt;i++)
		{
			if(a[i].a>top) b.push(a[i].b);
			else if(a[i].a<top&&!b.empty())
			{
				re tp=b.top();
				if(tp>top) tp=top;
				ans+=top--;sum+=tp;
				b.pop();i--;
			}
			else if(a[i].a<top)
			{
				top=a[i].a-1;
				ans+=a[i].a,sum+=a[i].b;
			}
			else
			{
				re f1=a[i].b,f2=0;
				if(!b.empty()) f2=b.top();
				if(f1>=f2) ans+=a[i].a,sum+=a[i].b,top=a[i].a-1;
				else
				{
					if(f2>top) f2=top;
					ans+=top--;sum+=f2;
					b.pop();b.push(a[i].b);
				}
			}
		}
		while(top&&!b.empty())
		{
			re fff=b.top();
			if(fff>top) fff=top;
			ans+=top--,sum+=fff;
			b.pop();
		}
		printf("%d %d\n",ans,sum);
	}
}