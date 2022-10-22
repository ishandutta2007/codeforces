#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,m,q,map[1010][1010],cnt[1010],tag[1010],head[100010],tot,Q[100010][3],ans[100010],now;
struct node
{
	int to,nextn;
}a[100010];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void fun(int u)
{
	int fb,fbnow=now;
	if(Q[u][0]<=2)
	{
		fb=map[Q[u][1]][Q[u][2]];
		cnt[Q[u][1]]-=fb^tag[Q[u][1]];
		now-=fb^tag[Q[u][1]];
		if(Q[u][0]==1) map[Q[u][1]][Q[u][2]]=tag[Q[u][1]]^1,++now;
		else map[Q[u][1]][Q[u][2]]=tag[Q[u][1]]^0;
		cnt[Q[u][1]]+=map[Q[u][1]][Q[u][2]]^tag[Q[u][1]];
	}
	if(Q[u][0]==3)
	{
		tag[Q[u][1]]^=1;
		now-=cnt[Q[u][1]];
		cnt[Q[u][1]]=m-cnt[Q[u][1]];
		now+=cnt[Q[u][1]];
	}
	ans[u]=now;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		fun(v);
	}
	if(Q[u][0]<=2) cnt[Q[u][1]]-=map[Q[u][1]][Q[u][2]]^tag[Q[u][1]],map[Q[u][1]][Q[u][2]]=fb,cnt[Q[u][1]]+=tag[Q[u][1]]^fb;
	if(Q[u][0]==3) tag[Q[u][1]]^=1,cnt[Q[u][1]]=m-cnt[Q[u][1]];
	now=fbnow;
}
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1,last=0;i<=q;last=i,++i)
	{
		Q[i][0]=read();
		if(Q[i][0]<=2) Q[i][1]=read(),Q[i][2]=read(),ADD(last,i);
		else if(Q[i][0]==4) Q[i][1]=read(),ADD(Q[i][1],i);
		else Q[i][1]=read(),ADD(last,i);
	}
	Q[0][0]=4;
	fun(0);
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}