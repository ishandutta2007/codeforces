#include<bits/stdc++.h>
typedef long long ll;
const int M=998244353;
const int G=3,INV2=(M+1)/2;
const int K=18;
inline int Mod(int a){return a<M?a:a-M;}
inline int Pow(int a,ll m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
namespace poly{
	int rev[1<<K],invn,t0[1<<K],t1[1<<K],t2[1<<K];
	inline void Init(int K){
		for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)*(1<<K-1);
		invn=Pow(1<<K,M-2);
	}
	inline void Ntt(int*a,int f,int K){
		int tmp,tmp1,s,w;
		for(int i=0;i<(1<<K);i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
		for(int k=1;k<(1<<K);k<<=1){
		  w=Pow(G,f>0?M/2/k:M-1-M/2/k);
		  for(int i=0;i<(1<<K);i+=k+k){
			s=1;
			for(int j=0;j<k;j++,s=(ll)s*w%M){
			  tmp=a[i+j],tmp1=(ll)a[i+k+j]*s%M;
			  a[i+j]=Mod(tmp+tmp1),a[i+k+j]=Mod(tmp-tmp1+M); 
			} 
		  }
		}
		if(f<0)for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*invn%M;
	}
	inline void Inv(int*c,int*a,int K){
		memset(c,0,sizeof(int)*(1<<K));
		memset(t0,0,sizeof(int)*(1<<K));
		c[0]=Pow(a[0],M-2);
		for(int j=1;j<K;j++){
		  memcpy(t0,a,sizeof(int)*(1<<j));
		  Init(j+1);
		  Ntt(c,1,j+1),Ntt(t0,1,j+1);
		  for(int i=0;i<(1<<j+1);i++)c[i]=(2-(ll)t0[i]*c[i]%M+M)*c[i]%M;
		  Ntt(c,-1,j+1);
		  memset(c+(1<<j),0,sizeof(int)*(1<<j));
		}
	}
	inline void Sqrt(int*c,int*a){
		memset(c,0,sizeof(int)*(1<<K));
		memset(t2,0,sizeof(int)*(1<<K));
		c[0]=M-1;
		for(int j=1;j<K;j++){
		  Inv(t1,c,j+1);
		  memcpy(t2,a,sizeof(int)*(1<<j));
		  Init(j+1);
		  Ntt(c,1,j+1),Ntt(t1,1,j+1),Ntt(t2,1,j+1);
		  for(int i=0;i<(1<<j+1);i++)c[i]=(t2[i]+(ll)c[i]*c[i])%M*t1[i]%M*INV2%M;
		  Ntt(c,-1,j+1);
		  memset(c+(1<<j),0,sizeof(int)*(1<<j));
		}
	}
}
int m,n,a[1<<K],b[1<<K],c[1<<K];
int main(){
	int x;
	scanf("%d%d",&m,&n);
	for(;m--;)scanf("%d",&x),++a[x];
	for(int i=0;i<(1<<K);i++)b[i]=((i==0)-4ll*a[i]%M+M)%M;
	poly::Sqrt(c,b),c[0]=(c[0]+1)%M;
	for(int i=0;i<(1<<K);i++)b[i]=2*a[i]%M;
	for(int i=0,j=0,f=0;i<(1<<K);i++,j+=f)
	  if(f=b[i]?1:f)b[j]=b[i],c[j]=c[i];
	poly::Inv(a,b,K);
	poly::Ntt(c,1,K),poly::Ntt(a,1,K);
	for(int i=0;i<(1<<K);i++)c[i]=(ll)c[i]*a[i]%M;
	poly::Ntt(c,-1,K);
	for(int i=1;i<=n;i++)printf("%d\n",c[i]);
	return 0;
}