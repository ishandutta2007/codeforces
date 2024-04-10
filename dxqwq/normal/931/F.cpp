// Problem: F. Teodor is not a liar!
// Contest: Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// URL: https://codeforces.com/contest/931/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1000003];
int tree[1000003];
void add(int x,int g)
{
	while(x<=1000000) tree[x]=max(tree[x],g),x+=x&(-x);
	return ;
}
int find(int x)
{
	int res=0;
	while(x) res=max(tree[x],res),x-=x&(-x);
	return res;
}
int ans[1000003];
int res[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) ++a[read()],--a[read()+1];
	for(int i=1; i<=m; i++) a[i]+=a[i-1];
	for(int i=1; i<=m; i++) 
	{
		ans[i]=find(a[i]+1)+1;
		add(a[i]+1,ans[i]);
		res[i]+=ans[i];
	}
	memset(tree,0,sizeof(tree));
	for(int i=m; i>=1; i--)
	{
		ans[i]=find(a[i]+1)+1;
		add(a[i]+1,ans[i]);
		res[i]+=ans[i];
	}
	int Ans=0;
	for(int i=1; i<=m; i++) Ans=max(Ans,res[i]-1);
	printf("%d ",Ans);
    return 0;
}