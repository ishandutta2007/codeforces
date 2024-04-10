#include <bits/stdc++.h>
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;i<(n);i++)
using namespace std;
int n,m,i,j;
long long ans;
int g[4];
int main(){
	scanf("%d",&n);
	rep(i,n){
		int x,y;scanf("%d%d",&x,&y);
		g[(x/2%2)*2+y/2%2]++; 
	}
	rep0(i,4){
		ans=(ans+1ll*g[i]*(g[i]-1)*(g[i]-2)/6);
	}
	rep0(i,4)rep0(j,4)if(i!=j){
		ans=(ans+1ll*g[i]*g[j]*(g[j]-1)/2);
	}
	cout<<ans<<endl;
	return 0;
}