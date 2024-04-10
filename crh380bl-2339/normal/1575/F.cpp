#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
ll d[100005],f[100005],p[100005];
int a[100005];
ll qpow(ll x,int y){
	ll t=1;
	while(y){
		if(y&1)t=t*x%mod;
		x=x*x%mod;
		y>>=1; 
	}
	return t;
}
ll inv(ll x){
	return qpow(x,mod-2);
}
int fac[100005],_fac[100005],sum[100005];
vector<int>S;
int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1LL*fac[n]*_fac[m]%mod*_fac[n-m]%mod;
}
int main(){
	int n,k,i,s=0,m=0,t,j;
	scanf("%d%d",&n,&k);
	d[1]=0;
	for(i=1;i<n;++i){
		d[i+1]=(1LL*i*(k-1)%mod*d[i]%mod-1LL*k*i%mod+mod)%mod*inv(n-i)%mod;
	}
	fac[0]=1;
	for(i=1;i<=100000;++i)fac[i]=1LL*fac[i-1]*i%mod;
	_fac[100000]=inv(fac[100000]);
	for(i=99999;i>=0;--i)_fac[i]=1LL*(i+1)*_fac[i+1]%mod;
	for(i=1;i<=n;++i)f[i]=(f[i-1]+d[i])%mod;
	ll ans=mod-f[n];
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;a[i]==-1&&i<=n;++i,++m);
	t=inv(k);
	for(i=0;i<=m;++i){
		p[i]=1LL*C(m,i)*qpow(t,i)%mod*qpow(mod+1-t,m-i)%mod;
	}
	s=0;int s1=0;
	for(i=m+1;i<=n;++i){
		if(i==m+1)s=s1=1;
		else if(a[i]==a[i-1])++s;
		else{
			++sum[s];
			++s1;
			if(sum[s]==1){
				S.push_back(s);
			}
			s=1;
		}
	}
	if(s){
		++sum[s];
		if(sum[s]==1){
			S.push_back(s);
		}
	}
	S.push_back(0);
	sum[0]=k-s1;
	for(i=0;i<S.size();++i){
		s=S[i];
		for(j=0;j<=m;++j){
			ans=(ans+1LL*p[j]*f[s+j]%mod*sum[s]%mod)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}