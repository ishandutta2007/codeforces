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
int n,q,L[MAXN],R[MAXN],val[MAXN];
int mem[15],f[MAXN][15],g[MAXN][15],dfn_f[MAXN],dfn_g[MAXN],z[MAXN],top,tim,pd[MAXN];
char s[MAXN];
void del(int x)
{
	R[L[x]]=R[x];
	L[R[x]]=L[x];
}
int main()
{
	n=read(),q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if('0'<=s[i] && s[i]<='9') val[i]=s[i]-'0';
		else val[i]=(s[i]=='<'?11:10);
		L[i]=i-1,R[i]=i+1;
	}
	++n; L[n]=n-1,R[n]=n+1;
	memset(dfn_f,0x3f,sizeof(dfn_f));
	memset(dfn_g,0x3f,sizeof(dfn_g));
	++tim;
	for(int l=1;l<=n;++l) if(dfn_f[l]==0x3f3f3f3f)
	{
		for(int cur=l,nex,way=10;l<=cur && cur<=n;cur=nex,++tim)
		{
			if(tim<dfn_f[cur])
			{
				dfn_f[cur]=tim;
				for(int i=0;i<10;++i) f[cur][i]=mem[i];
			}
			if(val[cur]<10)
			{
				mem[val[cur]]++;
				if(val[cur]) --val[cur];
				else del(cur);
			}
			else way=val[cur];
			nex=(way==11?L[cur]:R[cur]);
			if(val[nex]>9 && val[cur]>9) del(cur);
			if(!pd[cur]) z[++top]=cur,pd[cur]=1;
			if(way==11)
			{
				while(L[cur]<z[top] && z[top]<=cur && top)
				{
					dfn_g[z[top]]=++tim;
					for(int i=0;i<10;++i) g[z[top]][i]=mem[i];
					--top;
				}
			}
		}
	}
	while(q--)
	{
		int l=read(),r=read();
		if(dfn_f[r+1]<dfn_g[l])
		{
			for(int i=0;i<10;++i) printf("%d ",f[r+1][i]-f[l][i]);
			putchar('\n');
		}
		else
		{
			for(int i=0;i<10;++i) printf("%d ",g[l][i]-f[l][i]);
			putchar('\n');
		}
	}
	return 0;
}
//ore no turn,draw