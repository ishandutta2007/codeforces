#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mod=1e9+7;
int n,q,lim,i,j,k,b[105],c[105],sc[105],ans[200005];
int f[105][10005];
int solve(int lim){
	memset(f,0,sizeof(f));
	int ans=0;
	f[0][0]=1;rep(i,c[1]) f[0][i]=1;
	rep(i,n){
		for(j=max(0,lim*i+b[i-1]);j<=sc[i];j++){
			f[i][j]=(0ll+f[i-1][j]-(j<=c[i]?0:f[i-1][j-c[i]-1])+mod)%mod;
			if(i==n) ans=(ans+f[i][j])%mod; 
		}
		rep(j,sc[i+1]){
			f[i][j]=(f[i][j]+f[i][j-1])%mod;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&c[i]);
	rep(i,n-1)scanf("%d",&b[i]);
	rep(i,n-1)b[i]+=b[i-1];
	rep(i,n-1)b[i]+=b[i-1];
	rep(i,n)sc[i]=sc[i-1]+c[i];
	scanf("%d",&q);
	int r=100;
	while(r>=-100000&&n*r+b[n-1]>10000) r--;
	int l=r;
	while(l>=-100000&&(l>=0||n*l+b[n-1]>=0)){
		ans[l+100000]=solve(l);
		l--;
	}
	if(l>=-100000){
		ans[l+100000]=solve(l);
		l--;
	}
	l++;
	while(q--){
		int x;
		scanf("%d",&x);
		x=max(x,l);
		if(x>r){
			puts("0");
			continue;
		}
		printf("%d\n",ans[x+100000]);
	}
	return 0;
}