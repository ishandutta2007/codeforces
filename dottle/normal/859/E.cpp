#include<bits/stdc++.h>
#define int long long
const int N=1050000,mod=1e9+7;
using namespace std;

int ans=1;
int fa[N],sz[N],ct[N],fl[N];
int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}
int n;

main(){
	cin>>n;
	for(int i=1;i<=n<<1;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		int fx=gf(x),fy=gf(y);
		if(x==y)fl[fx]=1;
		if(fx==fy)ct[fx]++;
		else ct[fx]+=ct[fy]+1,fa[fy]=fx,sz[fx]+=sz[fy],fl[fx]|=fl[fy];
	}
	for(int i=1;i<=n<<1;i++){
		if(fa[i]==i){
			if(fl[i])continue;
			if(sz[i]==ct[i])ans=ans*2%mod;
			else ans=ans*sz[i]%mod;
		}
	}
	cout<<ans<<endl;
}