#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
const int mod=998244353;
int n,m;
char l[N],r[N];
int fac[N],invf[N];
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
inline int C(int x,int k){
	return 1ll*fac[x]*invf[k]%mod*invf[x-k]%mod;
}
int main(){
	int i,j;
	cin>>n;
	int lw=0,lb=0,rw=0,rb=0;
	for(i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		lw+=(l[i]=='W');
		rw+=(r[i]=='W');
		lb+=(l[i]=='B');
		rb+=(r[i]=='B');
	}
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invf[n]=po(fac[n],mod-2);
	for(i=n-1;i>=0;i--) invf[i]=invf[i+1]*ll(i+1)%mod;
	int ans=0;
	for(i=0;i<=n;i++){
		if(i<rb||i<lw) continue;
		if(n-i<rw||n-i<lb) continue;
		ans=(ans+1ll*C(n-rw-rb,i-rb)*C(n-lw-lb,i-lw))%mod;
	}
	for(i=1;i<=n;i++){
		if(l[i]==r[i]&&l[i]!='?'){
			cout<<ans;
			return 0;
		}
	}
	int cnt=0;
	int x=0,y=0;
	for(i=1;i<=n;i++){
		if(l[i]=='W'||r[i]=='B') x++;
		if(l[i]=='B'||r[i]=='W') y++;
	}
	for(i=1;i<n;i++){
		if(i<x||n-i<y) continue;
		ans=(ans-C(n-x-y,i-x)+mod)%mod;
	}
	cout<<ans;
	return 0;
}