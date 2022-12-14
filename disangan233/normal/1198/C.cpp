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
#define gc() getchar()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=3e5+5;
int n,m,ins[N],cnt;
int main()
{
	re opt=read();
	while(opt--)
	{
		n=read(),m=read();cnt=1;fill(ins+1,ins+3*n+1,1);
		re N=3*n,M=0;vector<int>vec;
		for(re i=1;i<=m;i++)
		{
			re u=read(),v=read();
			if(ins[u]&&ins[v]) ins[u]=ins[v]=0,N-=2,M++,vec.push_back(i);
		}
		if(N>=n)
		{
			puts("IndSet");
			for(re i=1,j=n;i<=3*n&&j;i++) if(ins[i]) printf("%d ",i),j--;
			puts("");
		}
		else if(M>=n)
		{
			puts("Matching");
			for(re i=0;i<n;i++) printf("%d ",vec[i]);
			puts("");
		}
		else puts("Impossible");
	}
}