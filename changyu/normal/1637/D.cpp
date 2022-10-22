#include<bits/stdc++.h>
#define int long long
const int N=103,INF=1e18;
int n,a[N],b[N],s1,s2,ans;
std::bitset<N*N>f;
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld",&n);
	s1=s2=0,ans=INF;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),s2+=a[i]*a[i],s1+=a[i];
	for(int i=1;i<=n;i++)scanf("%lld",b+i),s2+=b[i]*b[i],s1+=b[i];
	f.reset(),f[0]=1;
	for(int i=1;i<=n;i++)f=f<<a[i]|f<<b[i];
	for(int i=0;i<=s1;i++)if(f[i])ans=std::min(ans,(s1-i)*(s1-i)+i*i);
	printf("%lld\n",s2*(n-2)+ans);
	}return 0;
}