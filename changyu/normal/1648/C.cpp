#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+3,M=998244353;
int n,m,fac[N],a[N],b[N],bt[N],c[N],ans,s,t;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline void Add(int k,int a){for(;k<N;k+=k&-k)bt[k]+=a;}
inline int Sum(int k){int s=0;for(;k;k-=k&-k)s+=bt[k];return s;}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%M;
	for(int i=1;i<=n;i++)scanf("%d",a+i),++c[a[i]],Add(a[i],1);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	s=fac[n-1];
	t=n-1;
	for(int i=1;i<N;i++)if(c[i])s=(ll)s*Pow(fac[c[i]],M-2)%M;
	for(int i=1;i<=m;i++){
		ans=(ans+(ll)Sum(b[i]-1)*s)%M;
		s=(ll)s*c[b[i]]%M*Pow(t,M-2)%M;
		--t;
		--c[b[i]],Add(b[i],-1);
		if(c[b[i]]<0)break;
		if(i==n&&i<m){ans=(ans+1)%M;break;}
	}
	printf("%d\n",ans);
	return 0;
}