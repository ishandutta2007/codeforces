#include<bits/stdc++.h>
using namespace std;

const int p=998244353,maxN=2097152,g=3,ig=332748118,inv2=(p+1)/2;
int W[maxN],iW[maxN];
int fac[maxN],ifac[maxN],inv[maxN];
int qpow(int a,int k){
    int ans=1;
    while(k){
        if(k&1) ans=1LL*ans*a%p;
        a=1LL*a*a%p;
        k>>=1;
    }
    return ans;
}
void init(){
	int w=qpow(g,(p-1)/maxN),iw=qpow(ig,(p-1)/maxN);
    W[0]=iW[0]=1;
    for(int i=1;i<maxN;i++)
        W[i]=1LL*W[i-1]*w%p,
        iW[i]=1LL*iW[i-1]*iw%p;
    fac[0]=ifac[0]=fac[1]=ifac[1]=inv[1]=1;
    for(int i=2;i<maxN;i++)
    	fac[i]=1LL*fac[i-1]*i%p,
    	inv[i]=1LL*(p-p/i)*inv[p%i]%p,
    	ifac[i]=1LL*ifac[i-1]*inv[i]%p;
}
int R[maxN];
void NTT(int d[],bool flg,int n0){
    int x=1,len=0;while(x<n0) x<<=1,len++;
    for(int i=0;i<x;i++){
        R[i]=(R[i>>1]>>1)|((i&1)<<(len-1));
        if(i<R[i]) swap(d[i],d[R[i]]);
    }
    for(int i=1,l=maxN/(i<<1);i<x;i<<=1,l>>=1)
    for(int j=0;j<x;j+=(i<<1))
    for(int k=0,u=0;k<i;k++,u+=l){
        int a0=d[j|k],a1=1LL*(flg?iW[u]:W[u])*d[j|i|k]%p;
        d[j|k]=(a0+a1)%p;d[j|i|k]=a0-a1+p;
    	if(d[j|i|k]>=p)d[j|i|k]-=p;
	}
    if(flg){
        int invx=qpow(x,p-2);
        for(int i=0;i<x;i++) d[i]=1LL*d[i]*invx%p;
    }
}

int N,M;
int A[1000005];
bool flg[1000005];
int F[maxN],G[maxN];

int main(){
	init();
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),flg[A[i]]=1,F[A[i]]=1;
	int x=1;while(x<(2*M+1)) x<<=1;
	NTT(F,0,x);
	for(int i=0;i<x;i++) G[i]=1LL*F[i]*F[i]%p;
	NTT(G,1,x);
	for(int i=1;i<=M;i++) if(!flg[i]&&G[i]){printf("NO\n");return 0;}
	int ans=0;
	for(int i=1;i<=N;i++) if(!G[A[i]]) ans++;
	printf("YES\n%d\n",ans);
	for(int i=1;i<=N;i++) if(!G[A[i]]) printf("%d ",A[i]);
}