// Problem: E. Boolean Function
// Contest: Codeforces - Codeforces Round #323 (Div. 1)
// URL: https://codeforces.com/problemset/problem/582/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
const int M=16,N=65536;
int cnt=0,top=0;
int ls[503],rs[503];
char op[503];
int f[503][65536];
int st[503];
char s[503];
void FWT_OR(int*F)
{
	for(int w=2,j=1; w<=N; w<<=1,j<<=1)
		for(int i=0; i<N; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+j+k]+=F[i+k])>=p)&&(F[i+j+k]-=p);
}
void FWT_IOR(int*F)
{
	for(int w=2,j=1; w<=N; w<<=1,j<<=1)
		for(int i=0; i<N; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+j+k]-=F[i+k])<0)&&(F[i+j+k]+=p);
}
void FWT_AND(int*F)
{
	for(int w=2,j=1; w<=N; w<<=1,j<<=1)
		for(int i=0; i<N; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+k]+=F[i+j+k])>=p)&&(F[i+k]-=p);
}
void FWT_IAND(int*F)
{
	for(int w=2,j=1; w<=N; w<<=1,j<<=1)
		for(int i=0; i<N; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+k]-=F[i+j+k])<0)&&(F[i+k]+=p);
}
int tf[65536],tg[65536];
void dfs(int x)
{
	if(!ls[x])
	{
		for(int T=0; T<4; ++T)
			if(op[x]=='?'||op[x]=='A'+T) 
				for(int i=0; i<N; ++i) 
				{
					bool flg=1;
					for(int j=0; j<M&&flg; ++j) flg&=((i&(1<<j))>0)==((j&(1<<T))>0);
					f[x][i]+=flg;
				}	
		for(int T=0; T<4; ++T)
			if(op[x]=='?'||op[x]=='a'+T) 
				for(int i=0; i<N; ++i) 
				{
					bool flg=1;
					for(int j=0; j<M&&flg; ++j) flg&=((i&(1<<j))>0)==((j&(1<<T))==0);
					f[x][i]+=flg;
				}		
		return ;
	} 
	dfs(ls[x]),dfs(rs[x]);
	if(op[x]!='|')
	{
		memcpy(tf,f[ls[x]],N<<2),
		memcpy(tg,f[rs[x]],N<<2),
		FWT_AND(tf),FWT_AND(tg);
		for(int i=0; i<N; ++i) tf[i]=1ll*tf[i]*tg[i]%p;
		FWT_IAND(tf);
		for(int i=0; i<N; ++i) f[x][i]=(f[x][i]+tf[i])%p;
	}	
	if(op[x]!='&')
	{
		memcpy(tf,f[ls[x]],N<<2),
		memcpy(tg,f[rs[x]],N<<2),
		FWT_OR(tf),FWT_OR(tg);
		for(int i=0; i<N; ++i) tf[i]=1ll*tf[i]*tg[i]%p;
		FWT_IOR(tf);
		for(int i=0; i<N; ++i) f[x][i]=(f[x][i]+tf[i])%p;
	}
	return ;
}
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='(') st[++top]=-1;
		else if(s[i]==')') 
		{
			st[top-1]=st[top],--top;
			if(top>=3&&st[top-1]>0&&st[top-2]>0)
				ls[st[top-1]]=st[top-2],rs[st[top-1]]=st[top],
				st[top-2]=st[top-1],top-=2;
		}
		else st[++top]=++cnt,op[cnt]=s[i];
	}
	assert(top==1),dfs(st[1]);
	int A=0,B=0;
	for(int T=read(); T--;)
	{
		int s=0;
		for(int j=1; j<=8; j<<=1) (read())&&(s+=j);
		A+=1<<s,(read())&&(B+=1<<s);
	}
	int ans=0;
	for(int i=0; i<N; ++i) ((i&A)==B)&&(ans=(ans+f[st[1]][i])%p); 
	printf("%d\n",ans);
	return 0;
}