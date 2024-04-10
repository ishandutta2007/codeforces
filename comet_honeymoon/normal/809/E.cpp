#include<bits/stdc++.h>
#pragma optimize("O3")
using namespace std;

const int p=1000000007;

int qpow(int a,int k){
	int ans=1;
	while(k){
		if(k&1) ans=1LL*ans*a%p;
		a=1LL*a*a%p;
		k>>=1;
	}
	return ans;
}

bool flg[200005];
int pri[200005],tot;
int mu[200005],phi[200005];
void init(){
	mu[1]=1;phi[1]=1;
	for(int i=2;i<=200000;i++){
		if(!flg[i]) mu[i]=p-1,phi[i]=i-1,pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=200000;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0){mu[i*pri[j]]=0,phi[i*pri[j]]=phi[i]*pri[j];break;}
			else mu[i*pri[j]]=p-mu[i],phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}

int N;
int A[200005],B[200005];
int lnk[200005];
int pre[400005],tgt[400005],cnt;
void add_E(int u,int v){
	pre[++cnt]=lnk[u],tgt[cnt]=v,lnk[u]=cnt;
}
int dfn[200005],nfd[200005],rev[400005],idx;
int dep[200005],fa[200005];
void Get_dfn(int x,int f){
	dfn[x]=++idx;rev[idx]=x;
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=f)
		Get_dfn(tgt[e],x),rev[++idx]=x;
	nfd[x]=idx;
}
int lg2[400005];
int ST[400005][20];
int STmax(int a,int b){if(dep[a]<=dep[b]) return a;return b;}
void Get_ST(){
	for(int i=idx;i;i--){
		ST[i][0]=rev[i];
		for(int k=1;i+(1<<k)-1<=idx;k++)
			ST[i][k]=STmax(ST[i][k-1],ST[i+(1<<(k-1))][k-1]);
	}
	lg2[0]=-1;
	for(int i=1;i<=idx;i++) lg2[i]=lg2[i>>1]+1;
}
int LCA(int x,int y){
	x=dfn[x],y=dfn[y];
	if(x>y) swap(x,y);
	int k=lg2[y-x+1];
	return STmax(ST[x][k],ST[y-(1<<k)+1][k]);
}

bool invT[200005];
bool cmp(int a,int b){return dfn[a]<dfn[b];}
int F[200005];
int vT[200005],len;
int DP[200005];
int stk[200005],tp;
void Solve(int d){
	for(int i=d;i<=N;i+=d) vT[++len]=B[i],invT[B[i]]=1;
	sort(vT+1,vT+len+1,cmp);
	int S1=0,S2=0;
	for(int i=1;i<=len;i++) S1=(S1+phi[A[vT[i]]])%p,S2=(S2+1LL*phi[A[vT[i]]]*dep[vT[i]]%p)%p;
	F[d]=2LL*S1%p*S2%p;
	int tlen=len,lca;
	for(int i=1;i<tlen;i++) if(!invT[lca=LCA(vT[i],vT[i+1])]) vT[++len]=lca,invT[lca]=1;
	sort(vT+1,vT+len+1,cmp);
	
	for(int i=1;i<=len;i++){
		while(tp&&dfn[vT[i]]>=nfd[stk[tp]]){
			F[d]=(F[d]-4LL*DP[stk[tp-1]]%p*DP[stk[tp]]%p*dep[stk[tp-1]]%p+p)%p;
			DP[stk[tp-1]]=(DP[stk[tp-1]]+DP[stk[tp]])%p;
			tp--;
		}
		stk[++tp]=vT[i];
		if(A[vT[i]]%d==0) DP[vT[i]]=phi[A[vT[i]]];
		else DP[vT[i]]=0;
		F[d]=(F[d]-2LL*DP[vT[i]]%p*DP[vT[i]]%p*dep[vT[i]]%p+p)%p; 
	}
	while(tp>1){
		F[d]=(F[d]-4LL*DP[stk[tp-1]]%p*DP[stk[tp]]%p*dep[stk[tp-1]]%p+p)%p;
		DP[stk[tp-1]]=(DP[stk[tp-1]]+DP[stk[tp]])%p;
		tp--;
	}
	tp=0;
	
	for(int i=1;i<=len;i++) invT[vT[i]]=0,DP[vT[i]]=0;
	len=0;
}
int G[200005];

int main(){
	init();
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),B[A[i]]=i;
	for(int i=1;i<N;i++){
		int u,v;scanf("%d%d",&u,&v);
		add_E(u,v);add_E(v,u);
	}
	
	Get_dfn(1,0);
	Get_ST();
	for(int i=1;i<=N;i++) Solve(i);
	for(int i=1;i<=N;i++)
	for(int j=1;i*j<=N;j++)
		G[i]=(G[i]+1LL*mu[j]*F[i*j]%p)%p;
	int ans=0;
	for(int i=1;i<=N;i++) ans=(ans+1LL*G[i]*i%p*qpow(phi[i],p-2)%p)%p;
	printf("%d\n",1LL*ans*qpow(1LL*N*(N-1)%p,p-2)%p);
}