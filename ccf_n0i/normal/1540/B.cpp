#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mod=1e9+7;
int fac[405],inv[405],fi[405];
int pw(int x,int y){
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return z;
}
int c(int x,int y){
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int n,m,i,j,k,pre[205],sz[205],f[205][205],ans;
vector<int> e[205];
void dfs(int x,int p){
	sz[x]=1;
	dzd(e[x],itr)if(*itr!=p){
		dfs(*itr,x);
		sz[x]+=sz[*itr];
		pre[*itr]=x;
	}
}
int main(){
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	for(i=2;i<=402;i++){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}
	cin>>n;
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	rep(i,n) f[0][i]=1;
	rep(i,n){
		rep(j,n-i){
			f[i][j]=1ll*(f[i-1][j]+f[i][j-1])*inv[2]%mod;
		}
	}
	rep(i,n){
		rep(j,i-1){
			pre[i]=0;
			dfs(i,0);
			vector<int> v;
			int x=j;
			while(x!=i){
				v.push_back(x);
				x=pre[x];
			}
			ans=(ans+1ll*(n-sz[v.back()])*inv[n])%mod;
			for(k=v.size()-1;k>0;k--){
				int wei=sz[v[k]]-sz[v[k-1]];
				ans=(ans+1ll*wei*inv[n]%mod*f[v.size()-k][k])%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}