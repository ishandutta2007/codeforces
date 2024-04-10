#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,m,f[N],mod,Q,a[N],zero;
void Add(int x,int w){
	zero-=!a[x];
	a[x]=(a[x]+w)%mod;
	zero+=!a[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>mod;
	f[1]=f[2]=1;
	for(int i=3;i<=n;++i){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,x;i<=n;++i){
		cin>>x;
		a[i]=(a[i]-x+mod)%mod;
	}
	n+=2;
	for(int i=n;i>=2;--i){
		a[i]=(a[i]+2LL*mod-a[i-1]-a[i-2])%mod;
	}
	for(int i=1;i<=n;++i)if(!a[i])++zero;
	while(m--){
		char opt;
		int l,r;
		cin>>opt>>l>>r;
		int len=r-l+1;
		Add(l,opt=='A'?f[1]:mod-f[1]);
		Add(r+1,opt=='A'?mod-(f[len]+f[len-1])%mod:(f[len]+f[len-1])%mod);
		Add(r+2,opt=='A'?mod-f[len]:f[len]);
		cout<<(zero==n?"YES\n":"NO\n");
	}
	return 0;
}