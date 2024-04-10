//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[13][203];
int len[13];
int n;
int op[60003];
int f[60003][13],fc;
int fi[13][53],se[13][53];
int trans[503],trc;
char itrans[503];
int fcur[13];
int mp[53][2003];
void dfs(int x,int id,int s=0)
{
	if(id>n)
	{
		op[fc+1]=x,mp[x][s]=++fc;
		for(int i=1; i<=n; ++i) f[fc][i]=fcur[i];
		return ;
	}
	if(fi[id][x]) fcur[id]=fi[id][x],dfs(x,id+1,s);
	if(se[id][x]) fcur[id]=se[id][x],dfs(x,id+1,s+(1<<(id-1)));
	return ;
}
int ec;
int to[5000003],nxt[5000003],head[5000003];
int lst[60003];
int dep[60003];
void dfs2(int x)
{
	if(dep[x]) return ;
	for(int i=head[x]; i; i=nxt[i])
	{
		int y=to[i];
		dfs2(y);
		if(dep[y]>dep[x]) dep[x]=dep[y],lst[x]=y;
	}
	++dep[x];
	return ;
}
void addedge(int x,int y)
{
	to[++ec]=y,nxt[ec]=head[x],head[x]=ec;
}
signed main()
{
	for(char i='a'; i<='z'; ++i) trans[i]=++trc,itrans[trc]=i;
	for(char i='A'; i<='Z'; ++i) trans[i]=++trc,itrans[trc]=i;
	for(int T=read();T--;)
	{
		n=read(),fc=0;
		for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
		for(int i=1; i<=n; ++i)
		{
			len[i]=strlen(s[i]+1);
			for(int j=1; j<=52; ++j) fi[i][j]=se[i][j]=0;
			for(int j=1; j<=len[i]; ++j) 
				if(fi[i][trans[s[i][j]]]) se[i][trans[s[i][j]]]=j;
				else fi[i][trans[s[i][j]]]=j;
		}
		ec=0;
		for(int i=1; i<=52; ++i) dfs(i,1);
		for(int i=1; i<=fc; ++i) dep[i]=0,lst[i]=0,head[i]=0;
		if(!fc)
		{
			puts("0");
			puts("");
			continue;
		}
		for(int i=1; i<=fc; ++i)
			for(int j=1; j<=52; ++j)
			{
				bool flg=1;
				int sum=0;
				for(int k=1; k<=n; ++k)
				{
					if(fi[k][j]&&f[i][k]<fi[k][j]);
					else if(se[k][j]&&f[i][k]<se[k][j]) sum+=1<<(k-1);
					else 
					{
						flg=0;
						break;
					}
				}
				if(flg) addedge(mp[j][sum],i);
			}
		int ans=0,qwq=0;
		for(int i=1; i<=fc; ++i)
		{
			dfs2(i);
			if(dep[i]>ans) ans=dep[i],qwq=i;
		}
		printf("%d\n",ans);
		stack<char> stk;
		while(qwq) stk.push(itrans[op[qwq]]),qwq=lst[qwq];
		while(!stk.empty()) printf("%c",stk.top()),stk.pop();
		puts("");
	}
	return 0;
}