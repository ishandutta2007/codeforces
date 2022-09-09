#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mod=1e9+7;
int n,q,lim,i,j,k,b[105],c[105],sc[105],ans;
int f[105][10005];
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&c[i]);
	rep(i,n-1)scanf("%d",&b[i]);
	rep(i,n-1)b[i]+=b[i-1];
	rep(i,n-1)b[i]+=b[i-1];
	rep(i,n)sc[i]=sc[i-1]+c[i];
	scanf("%d%d",&q,&lim);
	f[0][0]=1;
	rep(i,n){
		for(j=max(0,lim*i+b[i-1]);j<=sc[i];j++){
			for(k=0;k<=c[i]&&k<=j;k++){
				f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
			}
			if(i==n) ans=(ans+f[i][j])%mod; 
		}
	}
	cout<<ans<<endl;
	return 0;
}