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
const int MAXN=1e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,last=1,pcnt=1,size[MAXN*2],tag[MAXN*2];
char s[MAXN*2];
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
struct SAM
{
	int len,fa,ch[26];
}sam[MAXN*2];
void sam_in(int c)
{
	int p=last,np=last=++pcnt;
	size[np]=1;
	sam[np].len=sam[p].len+1;
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
			int nq=++pcnt;
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[q].fa=sam[np].fa=nq;
			while(p && sam[p].ch[c]==q)
			{
				sam[p].ch[c]=nq;
				p=sam[p].fa;
			}
		}
	}
}
void fun(int u)
{
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		fun(v);
		size[u]+=size[v];
	}
}
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i) sam_in(s[i]-'a');
	for(int i=2;i<=pcnt;++i) Ed.ADD(sam[i].fa,i);
	fun(1);
	n=read();
	for(int p=1;p<=n;++p)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		int x=1,xl=0,ans=0;
		for(int i=1;i<len;++i)
		{
			int c=s[i]-'a';
			while(x && !sam[x].ch[c]) x=sam[x].fa,xl=sam[x].len;
			if(sam[x].ch[c]) x=sam[x].ch[c],++xl;
		}
		for(int i=len;i<len*2;++i)
		{
			int c=s[(i-1)%len+1]-'a';
			while(x && !sam[x].ch[c]) x=sam[x].fa,xl=sam[x].len;
			if(sam[x].ch[c]) x=sam[x].ch[c],++xl;
			if(xl>=len)
			{
				while(sam[sam[x].fa].len>=len) x=sam[x].fa,xl=sam[x].len;
				if(tag[x]!=p) ans+=size[x],tag[x]=p;
			}
			//cout<<"b "<<i<<" "<<xl<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw