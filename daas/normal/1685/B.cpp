#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,A,B,C,D,ton[2],pd[MAXN],z1[MAXN],z2[MAXN],top1,top2;
char s[MAXN];
int main()
{
	T=read();
	while(T--)
	{
		A=read(),B=read(),C=read(),D=read();
		scanf("%s",s+1);
		int n=A+B+2*C+2*D;
		ton[0]=ton[1]=0;
		for(int i=1;i<=n;++i) ++ton[s[i]-'A'],pd[i]=0;
		if(ton[0]!=A+C+D || ton[1]!=B+C+D) {puts("NO");continue;}
		int len=0;
		top1=top2=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && s[r+1]!=s[r]) ++r;
			if((r-l+1)%2) len+=(r-l+1)/2;
			else
			{
				if(s[l]=='A') z1[++top1]=(r-l+1)/2;
				else z2[++top2]=(r-l+1)/2;
			}
		}
		sort(z1+1,z1+top1+1);
		sort(z2+1,z2+top2+1);
		int cur1=1;
		while(cur1<=top1 && C)
		{
			int minn=min(C,z1[cur1]);
			C-=minn;
			z1[cur1]-=minn;
			if(!z1[cur1]) ++cur1;
			if(!C) break;
		}
		if(C)
		{
			int minn=min(C,len);
			C-=minn;
			len-=minn;
			if(C)
			{
				int cur2=top2;
				while(cur2>=1 && C)
				{
					int minn=min(C,z2[cur2]-1);
					C-=minn;
					z2[cur2]-=minn+1;
					if(!z2[cur2]) --cur2;
					if(!C) break;
				}
				if(C) puts("NO");
				else
				{
					int num=0;
					for(int i=1;i<=cur2;++i) num+=z2[i];
					puts(num>=D?"YES":"NO");
				}
			}
			else
			{
				int num=len;
				for(int i=1;i<=top2;++i) num+=z2[i];
				puts(num>=D?"YES":"NO");
			}
		}
		else
		{
			int num=len;
			for(int i=cur1;i<=top1;++i) num+=z1[i]-1;
			for(int i=1;i<=top2;++i) num+=z2[i];
			puts(num>=D?"YES":"NO");
		}
	}
	return 0;
}
//ore no turn,draw!