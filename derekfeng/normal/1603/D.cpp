#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=18,N=1e5+5,M=333;
int T,n;
ll f[20][100008];
ll phi[100008],pre[100008];
ll s1[100008][340],s2[100008][340];
int sqt[100008];
int pri[100008],tot;
bool flg[100008];
void init(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!flg[i])pri[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*pri[j]<=N;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	for(int i=1;i<=N;i++)pre[i]=pre[i-1]+phi[i];
}
void initc(){
	for(int i=1;i<=N;i++){
		ll sum=0;
		for(int l=1,r,c;l<=i;l=r+1){
			c=i/l,r=i/c,sum+=pre[c]*(r-l+1);
			for(int j=l;j<=r&&j<=M;j++)s1[i][j]=pre[c];
			if(c<=M)s2[i][c]=pre[c]*(r-l+1);
		}
		for(int j=1;j<=M;j++){
			s1[i][j]=sum,sum-=pre[i/j];
			s2[i][j]+=s2[i][j-1];
		}
	}
}
ll c(int l,int r){
	if(l<=M)return s1[r][l];
	return s2[r][r/l-1]+(r/(r/l)-l+1)*pre[r/l];
}
void trans(ll *f,ll *g,int L,int R,int l,int r){
	int mid=(l+r)>>1,pos;
	ll res=1e18;
	for(int i=L;i<=min(mid-1,R);i++){
		ll tmp=f[i]+c(i+1,mid);
		if(tmp<res)res=tmp,pos=i;
	}
	g[mid]=res;
	if(l<mid)trans(f,g,L,pos,l,mid-1);
	if(mid<r)trans(f,g,pos,R,mid+1,r);
}
void getdp(){
	for(int i=1;i<=N;i++)f[0][i]=1e18;
	for(int i=1;i<B;i++)trans(f[i-1],f[i],0,N-1,1,N);
}
int main(){
	init();
	initc();
	getdp();
	scanf("%d",&T);
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		if(ceil(log2(n))<k)printf("%d\n",n);
		else printf("%lld\n",f[k][n]);
	}
}