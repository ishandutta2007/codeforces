#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 200020
int n,m,a[maxn],in[maxn],dp[maxn];
vector<int>eg[maxn];
ll k;
struct edge{int u,v;}e[maxn];
bool cmp(edge x,edge y){
	return max(a[x.u],a[x.v])<max(a[y.u],a[y.v]);
}
queue<int>q;
bool check(int l){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i)eg[i].clear(),in[i]=0,dp[i]=0;
	for(int i=1;i<=l;++i)eg[e[i].u].push_back(e[i].v),++in[e[i].v];
	for(int i=1;i<=n;++i)if(!in[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)eg[u].size();++i){
			int v=eg[u][i];
			--in[v];
			if(!in[v])dp[v]=dp[u]+1,q.push(v);
		}
	}
	for(int i=1;i<=n;++i)if(in[i]||dp[i]>=k)return 1;
	return 0;
}
int main(){
	n=getint(),m=getint();
	scanf("%lld",&k);--k;
	for(int i=1;i<=n;++i)a[i]=getint();
	int tmpmn=a[1];
	for(int i=1;i<=n;++i)tmpmn=min(tmpmn,a[i]);
	if(!k){
		cout<<tmpmn<<endl;
		return 0; 
	}
	for(int i=1;i<=m;++i)e[i].u=getint(),e[i].v=getint(); 
	sort(e+1,e+m+1,cmp);
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(!check(mid))l=mid+1;
		else r=mid;
	}
	if(!check(l)){
		puts("-1");
		return 0;
	}
	printf("%d\n",max(a[e[l].u],a[e[l].v]));
	return 0;
}