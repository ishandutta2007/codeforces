#include<bits/stdc++.h>
using namespace std;
long long n,top,maxx,pos;
queue<long long> q;
long long fir[500000],nxt[500000],gett[500000],deep[500000],son[500000];
long long ans,cur;
void add(long long x,long long y){
	gett[++top]=y;
	nxt[top]=fir[x]; fir[x]=top;
}
void dfs(long long x,long long fa){
	son[x]=1;
	for (long long i=fir[x];i;i=nxt[i]){
		long long v=gett[i];
		if (v==fa) continue;
		deep[v]=deep[x]+1; 
		dfs(v,x); 
		son[x]+=son[v];
	}
}
void gett_ans(long long x,long long fa,long long num){
	ans=max(ans,num);
	for (long long i=fir[x];i;i=nxt[i]){
		long long v=gett[i];
		if (v==fa) continue;
		long long now=num+son[x]-son[v];
		gett_ans(v,x,num+n-2*son[v]);
	}
}
int main(){
	scanf("%I64d",&n);
	for (long long i=1;i<=n-1;++i){
		long long x,y;
		scanf("%I64d%I64d",&x,&y);
		add(x,y); add(y,x);
	}deep[1]=1;dfs(1,0);
	long long num=0;
	for (long long i=1;i<=n;++i) num+=deep[i];
	gett_ans(1,0,num);
	printf("%I64d",ans);
}