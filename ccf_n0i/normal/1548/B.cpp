#include <bits/stdc++.h>
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;i<(n);i++)
using namespace std;
int n,m,q,ans,lg[200005];
long long f[200005][19];
long long gcd(long long x,long long y){
	if(!y)return x;return gcd(y,x%y);
}
long long query(int l,int r){
	if(l==r) return 0;r--;
	int t=lg[r-l+1];
	return gcd(f[l][t],f[r-(1<<t)+1][t]);
}
void solve(){
	int i,j;
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&f[i][0]);
	rep(i,n-1) f[i][0]=abs(f[i+1][0]-f[i][0]);
	rep(j,18)rep(i,n-(1<<j)) f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	ans=0;
	j=1;rep(i,n){
		j=max(i,j);
		while(j+1<=n&&query(i,j+1)!=1) j++;
		ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
}
int main(){
	int i;
	for(i=2;i<=200002;i++) lg[i]=lg[i>>1]+1;
	int t;scanf("%d",&t); 
	while(t--){
		solve();
	}
	return 0;
}