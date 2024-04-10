#include<bits/stdc++.h>
using namespace std;
typedef double db;
db eps=1e-12;
int n,m,K,c[505];
int N,id[505],deg[505];
vector<int>g[505],p;
db f[505][505],gf[505][105];
db mt[105][105],sb[105][105];
db res[105],ser[105];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		if(c[i])id[i]=N++,p.push_back(i);
	}
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		u--,v--,deg[u]++,deg[v]++;
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		if(c[i])f[i][i]=1,gf[i][id[i]]=1;
		else{
			db mul=1.0/(db)deg[i];
			for(auto x:g[i])f[i][x]+=mul;
			f[i][i]-=1;
		}
	}
	for(int i=0;i<n;i++){
		if(fabs(f[i][i])<eps)
			for(int j=0;j<n;j++)if(fabs(f[j][i])>eps){
				swap(f[i],f[j]);swap(gf[i],gf[j]);break;
			}
		db t=f[i][i];
		for(int j=0;j<n;j++)f[i][j]/=t;
		for(int j=0;j<N;j++)gf[i][j]/=t;
		for(int j=i+1;j<n;j++)if(fabs(f[j][i])>eps){
			db t=f[j][i];
			for(int k=i;k<n;k++)f[j][k]-=t*f[i][k];
			for(int k=0;k<N;k++)gf[j][k]-=t*gf[i][k];
		}
	}
	for(int i=n-1;i;i--){
		for(int j=i-1;~j;j--){
			db t=f[j][i];f[j][i]=0;
			for(int k=0;k<N;k++)gf[j][k]-=t*gf[i][k];
		}
	}
	for(int i=0;i<N;i++){
		db mul=1.0/(db)deg[p[i]];
		for(auto x:g[p[i]]){
			if(c[x])mt[i][id[x]]+=mul;
			else{
				for(int j=0;j<N;j++)
					mt[i][j]+=gf[x][j]*mul;
			}
		}
	}
	for(int i=0;i<N;i++)res[i]=gf[0][i];
	K-=2;
	while(K){
		if(K&1){
			memset(ser,0,sizeof(ser));
			for(int i=0;i<N;i++)for(int j=0;j<N;j++)
				ser[j]+=res[i]*mt[i][j];
			memcpy(res,ser,sizeof(res));
		}
		memset(sb,0,sizeof(sb));
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				sb[i][j]+=mt[i][k]*mt[k][j];
		memcpy(mt,sb,sizeof(sb));K>>=1;
	}
	printf("%.8lf",res[N-1]);
}