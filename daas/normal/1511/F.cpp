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
const int mod=998244353;
inline int MOD(int x){return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,trie[100][26],cnt,tag[100];
char s[10];
void insert()
{
	int len=strlen(s+1),x=0;
	for(int i=1;i<=len;++i)
	{
		int c=s[i]-'a';
		if(!trie[x][c]) trie[x][c]=++cnt;
		x=trie[x][c];
	}
	tag[x]=1;
}
struct matrix
{
	int n,m,A[400][400];
	matrix operator *(const matrix &Z)const
	{
		matrix bck;
		bck.n=n;
		bck.m=Z.m;
		memset(bck.A,0,sizeof(bck.A));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				for(int k=1;k<=Z.m;++k)
					bck.A[i][k]=MOD(bck.A[i][k]+(ll)A[i][j]*Z.A[j][k]%mod-mod);
		return bck;
	}
}base,ans;
int vis[50][50],id[50][50],z[400][2],tim;
void fun(int u,int v)
{
	if(vis[u][v]) return;
	vis[u][v]=1;
	id[u][v]=++tim;
	z[tim][0]=u;
	z[tim][1]=v;
	if(tag[u]) fun(0,v);
	if(tag[v]) fun(u,0);
	for(int i=0;i<26;++i) if(trie[u][i] && trie[v][i]) fun(trie[u][i],trie[v][i]);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		insert();
	}
	fun(0,0);
	ans.n=tim,ans.m=1;
	base.n=tim,base.m=tim;
	ans.A[1][1]=1;
	for(int p=1;p<=tim;++p)
	{
		int i=z[p][0],j=z[p][1];
		for(int k=0;k<26;++k) if(trie[i][k] && trie[j][k])
		{
			int vi=trie[i][k],vj=trie[j][k];
			base.A[id[vi][vj]][id[i][j]]+=1;
			if(tag[vi]) base.A[id[0][vj]][id[i][j]]+=1;
			if(tag[vj]) base.A[id[vi][0]][id[i][j]]+=1;
			if(tag[vi] && tag[vj]) base.A[1][id[i][j]]+=1;
		}
	}
	while(m)
	{
		if(m&1) ans=base*ans;
		base=base*base;
		m>>=1;
	}
	printf("%d\n",ans.A[1][1]);
	return 0;
}