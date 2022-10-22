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
int T,n,ton[MAXN],a[MAXN],pd[MAXN],ans[MAXN];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=0;i<=n;++i) ton[i]=0;
		for(int i=1;i<=n;++i) ++ton[a[i]=read()];
		int st=0,now=1;
		while(ton[st]) ++st;
		ans[0]=0;
		while(now<=n)
		{
			ans[++ans[0]]=st;
			int num=st,tmp=st;
			for(int i=0;i<st;++i) pd[i]=0;
			while(1)
			{
				if(a[now]<tmp)
				{
					if(!pd[a[now]]) pd[a[now]]=1,--num;
				}
				--ton[a[now]];
				if(!ton[a[now]]) st=min(st,a[now]);
				++now;
				if(!num) break;
			}
		}
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!