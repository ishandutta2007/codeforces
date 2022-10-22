#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=998244353;
int	inv(int x){
	int ans=1,res=x%M,t=M-2;
	for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
int n,K,a[300004],fa[300004],d[300004];
vector<int>g[300004],ver[3];
int f[300004][2];
void dfs(int x){
	for(auto y:g[x])if(y!=fa[x])
		fa[y]=x,d[y]=d[x]+1,dfs(y);
}
void sol(vector<int>&ar,int x){
	priority_queue<pii>pq;
	for(auto z:ar)pq.push({d[z],z});
	while(pq.size()>1){
		pii u=pq.top();pq.pop();
		int z=fa[u.se];
		if(a[z]==0)a[z]=x,pq.push({d[z],z});
		else if(a[z]!=x){
			puts("0");
			exit(0);
		}
	}
}
void dp(int x){
	int tmp=1;
	for(auto y:g[x])if(y!=fa[x])
		dp(y),tmp=(ll)tmp*(f[y][0]+f[y][1])%M;
	if(a[x])f[x][1]=tmp;
	else{
		f[x][0]=tmp;
		for(auto y:g[x])if(y!=fa[x])
			f[x][1]=((ll)tmp*inv(f[y][0]+f[y][1])%M*f[y][1]%M+f[x][1])%M;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ver[a[i]].push_back(i);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=2;i++)sol(ver[i],i);
	dp(1);
	printf("%d",f[1][1]);
}