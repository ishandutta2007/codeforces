#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
const int K=19,M=998244353,G=3;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
const int N=1<<K;
const char C[5]="ATGC";
int n,m,t,rev[N],c[N],s[N],ans,f[N],g[N],p[N],q[N],r[N];char a[N],b[N];
inline void Init(){
	for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)<<K-1;
}
inline void Ntt(int*a,int f){
	int tmp,tmp1,s,w;
	for(int i=0;i<N;i++)if(i<rev[i])
	  tmp=a[i],a[i]=a[rev[i]],a[rev[i]]=tmp;
	for(int k=1;k<N;k<<=1){
	  w=Pow(G,f>0?M/2/k:M-1-M/2/k);
	  for(int i=0;i<N;i+=k+k){
		s=1;
		for(int j=0;j<k;j++,s=(ll)s*w%M){
		  tmp=(ll)a[i+k+j]*s%M;
		  (a[i+k+j]=a[i+j]-tmp)<0&&(a[i+k+j]+=M);
		  (a[i+j]+=tmp)>=M&&(a[i+j]-=M);
		}
	  }
	}
	if(f<0){
	  tmp=Pow(N,M-2);
	  for(int i=0;i<N;i++)a[i]=(ll)a[i]*tmp%M;
	}
}
int main(){
	int tmp;
	scanf("%d%d%d%s%s",&n,&m,&t,a,b);
	for(int i=m-1;i<n;i++)s[i]=1;
	Init();
	for(int k=0;k<4;k++){
	  c[0]=a[0]==C[k];
	  for(int i=1;i<n;i++)c[i]=c[i-1]+(a[i]==C[k]);
	  for(int i=0;i<n;i++)p[i]=(i+t<n?c[i+t]:c[n-1])-(i-t-1>=0?c[i-t-1]:0)?1:2;
	  tmp=0;
	  for(int j=0;j<m;j++)q[j]=b[m-j-1]==C[k],tmp+=q[j];
	  for(int i=m-1;i<n;i++)r[i]=tmp;
	  memset(f,0,sizeof f),memset(g,0,sizeof g);
	  for(int i=0;i<n;i++)f[i]=p[i]*p[i];
	  for(int j=0;j<m;j++)g[j]=q[j];
	  Ntt(f,1),Ntt(g,1);
	  for(int i=0;i<(1<<K);i++)f[i]=(ll)f[i]*g[i]%M;
	  Ntt(f,-1);
	  for(int i=m-1;i<n;i++)r[i]=(r[i]+f[i])%M;
	  memset(f,0,sizeof f),memset(g,0,sizeof g);
	  for(int i=0;i<n;i++)f[i]=p[i];
	  for(int j=0;j<m;j++)g[j]=q[j];
	  Ntt(f,1),Ntt(g,1);
	  for(int i=0;i<(1<<K);i++)f[i]=(ll)f[i]*g[i]%M;
	  Ntt(f,-1);
	  for(int i=m-1;i<n;i++)r[i]=(r[i]-2ll*f[i]+M+M)%M;
	  for(int i=m-1;i<n;i++)
		s[i]&=!r[i];
	}
	for(int i=m-1;i<n;i++)ans+=s[i];
	printf("%d\n",ans);
	return 0;
}