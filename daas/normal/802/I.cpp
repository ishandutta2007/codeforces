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
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,cnt,size[MAXN*2];
char s[MAXN];
struct SAM
{
	int fa,len,ch[26];
}sam[MAXN*2];
int NEW()
{
	size[++cnt]=0;
	memset(sam[cnt].ch,0,sizeof(sam[cnt].ch));
	return cnt;
}
int sam_in(int p,int c)
{
	int np=NEW();
	sam[np].len=sam[p].len+1;
	size[np]=1;
	while(p && !sam[p].ch[c])
	{
		sam[p].ch[c]=np;
		p=sam[p].fa;
	}
	if(!p) sam[np].fa=1;
	else
	{
		int q=sam[p].ch[c];
		if(sam[q].len==sam[p].len+1) sam[np].fa=q;
		else
		{
			int nq=NEW();
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[np].fa=sam[q].fa=nq;
			while(p && sam[p].ch[c]==q)
			{
				sam[p].ch[c]=nq;
				p=sam[p].fa;
			}
		}
	}
	return np;
}
struct node
{
	int head[MAXN*2],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
void Pick(int u)
{
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		Pick(v);
		size[u]+=size[v];
	}
}
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=0;
		for(int i=1,las=NEW();i<=n;++i) las=sam_in(las,s[i]-'a');
		for(int i=1;i<=cnt;++i) Ed.head[i]=0;
		Ed.tot=0;
		for(int i=2;i<=cnt;++i) Ed.ADD(sam[i].fa,i);
		Pick(1);
		ll ans=0;
		for(int i=1;i<=cnt;++i) ans+=(ll)size[i]*size[i]*(sam[i].len-sam[sam[i].fa].len);
		printf("%lld\n",ans);
	}
	return 0;
}
//ore no turn,draw!