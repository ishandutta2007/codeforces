#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[22][50005];
int s[22];
int ksm(int x,int y){
	int t=1LL;
	while(y){
		if(y&1)t=1LL*t*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return t;
}
int main(){
	int n,m,i,j,k,s1,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(i=1;i<=m;++i){
		memset(s,0,sizeof(s));
		for(j=1;j<=n;++j){
			--a[j][i];
			if(a[j][i]>n)a[j][i]=n;
			++s[a[j][i]];
		}
		s1=1;
		for(j=n;j>=1;--j){
			if(j<n)s[j]+=s[j+1]-1;
			s1=1LL*s1*s[j]%mod;
		}
		if(s[0])s1=0;
		//printf("%d\n",s1);
		for(j=1;j<=n;++j)s1=1LL*s1*ksm(j,mod-2)%mod;
		s1=(1-s1+mod)%mod;
		ans=(ans+s1)%mod;
	}
	printf("%d\n",ans);
	return 0;
}