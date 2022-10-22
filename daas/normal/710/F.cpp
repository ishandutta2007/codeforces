#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,trie[6000001][26],fail[6000001],tot,num[6000001],cnt[2],dl[300001],h,t;
struct data
{
	int num,root;
	vector<string> mem;
}G[20][2];
string s;
void Make(int id,int ver)
{
	while(id!=1)
	{
		if(G[id][ver].num!=G[id-1][ver].num)
			break;
		for(int i=1;i<=G[id][ver].num;++i)
			(G[id-1][ver].mem).push_back(G[id][ver].mem[i-1]);
		(G[id][ver].mem).clear();
		G[--id][ver].num*=2;
	}
	G[id][ver].root=++tot;
	for(int i=1;i<=G[id][ver].num;++i)
	{
		int len=(G[id][ver].mem[i-1]).length(),bj=G[id][ver].root;
		for(int j=0;j<len;++j)
		{
			int c=G[id][ver].mem[i-1][j]-'a';
			if(!trie[bj][c])
				trie[bj][c]=++tot;
			bj=trie[bj][c];
		}
		++num[bj];
	}
	h=t=0;
	for(int i=0;i<26;++i)
		if(trie[G[id][ver].root][i])
			dl[++t]=trie[G[id][ver].root][i],fail[trie[G[id][ver].root][i]]=G[id][ver].root;
		else
			trie[G[id][ver].root][i]=G[id][ver].root;
	while(h!=t)
	{
		int u=dl[++h];
		num[u]+=num[fail[u]];
		for(int i=0;i<26;++i)
			if(trie[u][i])
			{
				fail[trie[u][i]]=trie[fail[u]][i];
				dl[++t]=trie[u][i];
			}
			else
				trie[u][i]=trie[fail[u]][i];
	}
	cnt[ver]=id;
}
int cx(int id,int ver)
{
	int bj=G[id][ver].root,len=s.length(),bck=0;
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		bj=trie[bj][c];
		bck+=num[bj];
	}
	return bck;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int type=read();
		cin>>s;
		if(type==1)
		{
			(G[++cnt[0]][0].mem).push_back(s);
			G[cnt[0]][0].num=1;
			Make(cnt[0],0);
		}
		if(type==2)
		{
			(G[++cnt[1]][1].mem).push_back(s);
			G[cnt[1]][1].num=1;
			Make(cnt[1],1);
		}
		if(type==3)
		{
			int ans=0;
			for(int j=1;j<=cnt[0];++j)
				ans+=cx(j,0);
			for(int j=1;j<=cnt[1];++j)
				ans-=cx(j,1);
			printf("%d\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}