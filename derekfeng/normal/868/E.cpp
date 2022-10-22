#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,s,m,N,v[104],w[104],sz[104];
vector<int>tr[54];
int f[104][54][54];
int getsz(int x,int fa){
	int tmp=sz[x];
	for(auto y:tr[x])if(v[y]!=fa)
		tmp+=getsz(v[y],x);
	return tmp;
}
int getdp(int x,int a,int b){
	int u=v[x];
	if(tr[u].size()==1){
		if(a==b)return 0;
		return getdp(tr[u][0],a-b,a-b)+w[x];
	}
	if(~f[x][a][b])return f[x][a][b];
	int L=0,R=1e6;
	while(R>L+1){
		int md=(L+R)>>1,KK=b;
		for(auto y:tr[u])if((x>>1)!=(y>>1)){
			for(int it=1;KK;it++){
				if(getdp(y,a,it)+w[y]<md)break;
				KK--;
			}
		}
		if(!KK)L=md;else R=md;
	}
	return f[x][a][b]=L;
}
int main(){
	scanf("%d",&n),memset(f,-1,sizeof(f));
	for(int i=1;i<n;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		v[N]=b,w[N]=c,tr[a].push_back(N),++N;
		v[N]=a,w[N]=c,tr[b].push_back(N),++N;
	}
	scanf("%d%d",&s,&m);
	for(int i=0,x;i<m;i++)scanf("%d",&x),sz[x]++;
	int ans=inf;for(auto y:tr[s]){
		int t=getsz(v[y],s);
		if(t)ans=min(ans,getdp(y,m,t)+w[y]);
	}
	printf("%d",ans);
}