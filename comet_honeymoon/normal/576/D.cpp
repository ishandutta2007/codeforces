#include<bits/stdc++.h>
using namespace std;

int N,M;
int U[155],V[155],D[155],id[155];
bool cmp(int a,int b){return D[a]<D[b];}
bool flg[155][155];
struct Mat{
	bitset<150> a[150];
	Mat(){for(int i=0;i<N;i++) a[i]=0;}
	Mat operator *(const Mat b)const{
		Mat c;
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(a[i][j]) c.a[i]|=b.a[j];
		return c;
	}
	Mat qpow(int k){
		Mat b=*this,ans;
		for(int i=0;i<N;i++) ans.a[i][i]=1;
		while(k){
			if(k&1) ans=ans*b;
			b=b*b;
			k>>=1;
		}
		return ans;
	}
}G,powG;

int q[155],h,t;int dis[155];
int ans=0x3f3f3f3f;

int main(){
	flg[0][0]=1;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++) scanf("%d%d%d",&U[i],&V[i],&D[i]),U[i]--,V[i]--,id[i]=i;
	sort(id+1,id+M+1,cmp);
	for(int k=0;k<=M;k++){
		h=t=0;
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<N;i++) if(flg[k][i]) dis[i]=0,q[++t]=i;
		while(h!=t){
			int u=q[++h];
			for(int i=0;i<N;i++) if(G.a[i][u]&&dis[i]==0x3f3f3f3f)
				dis[i]=dis[u]+1,q[++t]=i;
		}
		ans=min(ans,D[id[k]]+dis[N-1]);
		if(k!=M){
			powG=G.qpow(D[id[k+1]]-D[id[k]]);
			for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) if(powG.a[i][j])
				flg[k+1][i]|=flg[k][j];
			G.a[V[id[k+1]]][U[id[k+1]]]=1;
		}
	}
	if(ans!=0x3f3f3f3f)
		printf("%d\n",ans);
	else printf("Impossible\n");

	return 0;
}