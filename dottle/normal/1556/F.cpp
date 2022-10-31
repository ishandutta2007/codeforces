#include<bits/stdc++.h>
#define int long long
const int N=15,mod=1e9+7;
using namespace std;

int n,a[N],d[N][1<<N],f[1<<N],ans,dg[1<<N];
map<int,int> g[1<<N]; 

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int G(int x,int y){
	if(g[x][y])return g[x][y];
	int s=1;
	for(int i=0;i<n;i++)
		if(x>>i&1)
			s=s*d[i][y]%mod;
	return g[x][y]=s;
}

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<1<<n;i++)dg[i]=dg[i-(i&-i)]+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<1<<n;j++){
			d[i][j]=1;
			for(int k=0;k<n;k++)
				if(j>>k&1)
					d[i][j]=d[i][j]*a[i]%mod*inv(a[i]+a[k])%mod;
		}
	for(int i=1;i<1<<n;i++){
		f[i]=1;
		for(int j=(i-1)&i;j;j=(j-1)&i)
			f[i]-=f[j]*G(j,i-j)%mod;
		f[i]%=mod;
		ans+=f[i]*G(i,(1<<n)-1-i)%mod*dg[i]%mod; 
	}
	printf("%lld",(ans%mod+mod)%mod);
}