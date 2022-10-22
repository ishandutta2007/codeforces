#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int n,k,siz[200004];
vector<int>tr[200004];
void dfs(int x,int fa){
	siz[x]=1;
	for(auto y:tr[x])if(y!=fa)
		dfs(y,x),siz[x]+=siz[y];
}
int fc[200004],iv[200004];
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
void init(){
	const int N=2e5+3;
	fc[0]=1;
	for(int i=1;i<=N;i++)fc[i]=(ll)fc[i-1]*i%M;
	iv[N]=myp(fc[N],M-2);
	for(int i=N;i;i--)iv[i-1]=(ll)iv[i]*i%M;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*iv[b]%M*iv[a-b]%M;
}
vector<int>v[200004];
int main(){
	init(),scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back(v),tr[v].push_back(u);
	}
	dfs(1,0);int ans=0;
	for(int i=1;i<=n;i++)
		for(auto x:tr[i]){
			if(siz[x]<siz[i])v[i].push_back(siz[x]);
			else v[i].push_back(n-siz[i]);
		}
	for(int i=1;i<=n;i++){
		(ans+=(ll)C(n-1,k-1)*n%M)%=M;
		int all=C(n-1,k);
		for(auto x:v[i])
			(all+=M-C(x,k))%=M;
		(ans+=(ll)all*n%M)%=M;
	}
	for(int i=1;i<=n;i++){
		int all=0;
		for(auto x:v[i])(all+=C(x,k))%=M;
		for(auto x:v[i]){
			(all+=M-C(x,k))%=M;
			(ans+=(ll)(C(n-x,k)+M-all)*x%M*(n-x)%M)%=M;
			(all+=C(x,k))%=M;
		}
	}
	printf("%d",ans);
}