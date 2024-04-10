#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int G=3,Gi=332748118;
int n,k,f,lg,N=1;
int v[524300],rev[524300];
int myp(int x,int t){int a=1;for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;return a;}
void ntt(int *A,int z){
	for(int i=0;i<N;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int t=2;t<=N;t<<=1){
		int md=(t>>1),Wn=myp(z==1?G:Gi,(M-1)/t);
		for(int j=0;j<N;j+=t){
			for(int k=0,w=1;k<md;k++,w=(ll)w*Wn%M){
				int x=A[j+k],y=(ll)A[j+md+k]*w%M;
				A[j+k]=(x+y)%M,A[j+md+k]=(x-y+M)%M;
			}
		}
	}
	if(z<0){int iv=myp(N,M-2);for(int i=0;i<N;i++)A[i]=(ll)A[i]*iv%M;}
}
int main(){
	scanf("%d%d%d",&n,&k,&f);while(N<=k+k)N<<=1,lg++;
	for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<=k;i++)v[i]=1;
	for(int t=1;t<=n;t++){
		ntt(v,1);for(int i=0;i<N;i++)v[i]=(ll)v[i]*v[i]%M;ntt(v,-1);
		if(t!=n){
			for(int i=N-1,sm=0;~i;i--){
				int vv=v[i];if(i>k)v[i]=0;
				else v[i]=((ll)vv*(k-i+1)+sm)%M;
				(sm+=vv)%=M;
			}
		}
	}
	printf("%d\n",v[f]);
}