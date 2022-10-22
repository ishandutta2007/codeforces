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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,val[200010],F,flag,z[200010],ans1,ans2,X,tmp[200010];
void check(int x)
{
	int num=0;
	for(int i=1;i<m;++i) if(val[(x-1)*m+i]>val[(x-1)*m+i+1]) z[++num]=i;
	if(num>=3) {flag=F=1;return;}
	if(!num) return;
	X=x;
	F=1;
	if(num==2)
	{
		ans1=z[1];
		ans2=z[2]+1;
	}
	else
	{
		ans1=z[1];
		ans2=-1;
		/*ans2=z[1]+1;
		while(ans2+1<=m && val[(x-1)*m+ans2]==val[(x-1)*m+ans2+1]) ++ans2;*/
	}
}
int calc()
{
	for(int i=1;i<=n;++i) swap(val[(i-1)*m+ans1],val[(i-1)*m+ans2]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			if(val[(i-1)*m+j]>val[(i-1)*m+j+1])
				return 0;
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				val[(i-1)*m+j]=read();
		flag=F=0;
		for(int i=1;i<=n && !F;++i) check(i);
		if(!F) {puts("1 1");continue;}
		if(flag) {puts("-1");continue;}
		if(ans2==-1)
		{
			for(int i=1;i<=n*m;++i) tmp[i]=val[i];
			ans2=ans1+1;
			while(ans2+1<=m && val[(X-1)*m+ans2]==val[(X-1)*m+ans2+1]) ++ans2;
			if(calc()) {printf("%d %d\n",ans1,ans2);continue;}
			for(int i=1;i<=n*m;++i) val[i]=tmp[i];
			ans2=ans1+1;
			while(ans1-1>=1 && val[(X-1)*m+ans1]==val[(X-1)*m+ans1-1]) --ans1;
			if(calc()) {printf("%d %d\n",ans1,ans2);continue;}
			puts("-1");
		}
		else if(calc()) printf("%d %d\n",ans1,ans2);
		else puts("-1");
	}
	return 0;
}
//ore no turn,draw!