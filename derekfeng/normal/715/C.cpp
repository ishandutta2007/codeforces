#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int M;
struct E{
	int to,w;
	E(int to,int w):to(to),w(w){}
};
int n;
vector<E>g[100004];
bool rt[100004];
int sz[100004],N;
int dfs(int x,int p){
	sz[x]=1;
	for(auto y:g[x])if(y.to!=p&&!rt[y.to])sz[x]+=dfs(y.to,x);
	return sz[x];
}
int findr(int x,int p){
	int maxs=0;
	for(auto y:g[x])if(y.to!=p&&!rt[y.to]){
		int tmp=findr(y.to,x);
		if(tmp>=0)return tmp;
		maxs=max(maxs,sz[y.to]);
	}
	if(max(maxs,N-sz[x])<=N/2)return x;
	return -1;
}
map<int,int>mp;
int p10[100004];
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=extgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
ll got(int A,int B){
	ll NXT=M-B;
	ll X,Y;
	ll G=extgcd(A,M,X,Y);
	X%=M;
	if(X<0)X+=M; 
	return (X*NXT/G)%M;
}
void go1(int x,int len,ll num,int p,bool ok){
	int val=got(p10[len],num);
	ans+=mp[val];
	if(ok&&num==0)ans++;
	for(auto y:g[x])if(y.to!=p&&!rt[y.to])go1(y.to,len+1,(num*10+y.w)%M,x,ok);
}
void go2(int x,int len,ll num,int p,bool ok){
	mp[num]++;
	if(ok&&num==0)ans++;
	for(auto y:g[x])if(y.to!=p&&!rt[y.to])go2(y.to,len+1,(num+1ll*p10[len]*y.w)%M,x,ok);
}
void daq(int x){
	N=dfs(x,0);
	int root=findr(x,0);
	rt[root]=1;
	mp.clear();
	for(auto y:g[root])if(!rt[y.to]){
		go1(y.to,1,y.w%M,-1,1);
		go2(y.to,1,y.w%M,-1,1);
	}
	mp.clear();
	reverse(g[root].begin(),g[root].end());
	for(auto y:g[root])if(!rt[y.to]){
		go1(y.to,1,y.w%M,-1,0);
		go2(y.to,1,y.w%M,-1,0);
	}
	for(auto y:g[root])if(!rt[y.to])daq(y.to);
}
int main(){
	scanf("%d%d",&n,&M);
	p10[0]=1;
	for(int i=1;i<=n;i++)p10[i]=1ll*p10[i-1]*10%M;
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(E(v,w)),g[v].push_back(E(u,w)); 
	}
	daq(0);
	printf("%I64d",ans);
}