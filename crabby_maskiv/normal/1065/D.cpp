#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll g[N][N];
int f(int x,int y,int c){
	return c*100+(((x-1)*10)+(y-1))+1;
}
bool ok(int x,int y){
	return (x>0)&&(y>0)&&(x<=n)&&(y<=n);
}
int x[N],y[N];
int a[N][N];
int dp[N][3];
int main(){
	ios::sync_with_stdio(0);
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++){
    		cin>>a[i][j];
    		x[a[i][j]]=i;
    		y[a[i][j]]=j;
		}
	memset(g,0x3f,sizeof(g));
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		g[f(i,j,0)][f(i,j,1)]=1001;
    		g[f(i,j,1)][f(i,j,0)]=1001;
    		g[f(i,j,0)][f(i,j,2)]=1001;
    		g[f(i,j,2)][f(i,j,0)]=1001;
    		g[f(i,j,1)][f(i,j,2)]=1001;
    		g[f(i,j,2)][f(i,j,1)]=1001;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(ok(i-1,j-2)) g[f(i,j,0)][f(i-1,j-2,0)]=1000;
			if(ok(i-2,j-1)) g[f(i,j,0)][f(i-2,j-1,0)]=1000;
			if(ok(i-1,j+2)) g[f(i,j,0)][f(i-1,j+2,0)]=1000;
			if(ok(i-2,j+1)) g[f(i,j,0)][f(i-2,j+1,0)]=1000;
			if(ok(i+1,j-2)) g[f(i,j,0)][f(i+1,j-2,0)]=1000;
			if(ok(i+2,j-1)) g[f(i,j,0)][f(i+2,j-1,0)]=1000;
			if(ok(i+1,j+2)) g[f(i,j,0)][f(i+1,j+2,0)]=1000;
			if(ok(i+2,j+1)) g[f(i,j,0)][f(i+2,j+1,0)]=1000;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(ok(i-k,j-k)) g[f(i,j,1)][f(i-k,j-k,1)]=1000;
				if(ok(i-k,j+k)) g[f(i,j,1)][f(i-k,j+k,1)]=1000;
				if(ok(i+k,j-k)) g[f(i,j,1)][f(i+k,j-k,1)]=1000;
				if(ok(i+k,j+k)) g[f(i,j,1)][f(i+k,j+k,1)]=1000;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(ok(i-k,j)) g[f(i,j,2)][f(i-k,j,2)]=1000;
				if(ok(i,j-k)) g[f(i,j,2)][f(i,j-k,2)]=1000;
				if(ok(i+k,j)) g[f(i,j,2)][f(i+k,j,2)]=1000;
				if(ok(i,j+k)) g[f(i,j,2)][f(i,j+k,2)]=1000;
			}
		}
	}
	for(k=1;k<N;k++){
		for(i=1;i<N;i++)
			for(j=1;j<N;j++)
				if(g[i][k]+g[k][j]<g[i][j])
					g[i][j]=g[i][k]+g[k][j];
	}
	dp[1][0]=dp[1][1]=dp[1][2]=0;
	for(i=2;i<=n*n;i++){
		int _x=x[i-1],_y=y[i-1],x_=x[i],y_=y[i];
		ll dis00=g[f(_x,_y,0)][f(x_,y_,0)];
		ll dis01=g[f(_x,_y,0)][f(x_,y_,1)];
		ll dis02=g[f(_x,_y,0)][f(x_,y_,2)];
		ll dis10=g[f(_x,_y,1)][f(x_,y_,0)];
		ll dis11=g[f(_x,_y,1)][f(x_,y_,1)];
		ll dis12=g[f(_x,_y,1)][f(x_,y_,2)];
		ll dis20=g[f(_x,_y,2)][f(x_,y_,0)];
		ll dis21=g[f(_x,_y,2)][f(x_,y_,1)];
		ll dis22=g[f(_x,_y,2)][f(x_,y_,2)];
		dp[i][0]=min(min(dp[i-1][0]+dis00,dp[i-1][1]+dis10),dp[i-1][2]+dis20);
		dp[i][1]=min(min(dp[i-1][0]+dis01,dp[i-1][1]+dis11),dp[i-1][2]+dis21);
		dp[i][2]=min(min(dp[i-1][0]+dis02,dp[i-1][1]+dis12),dp[i-1][2]+dis22);
	}
	ll ans=min(dp[n*n][0],min(dp[n*n][1],dp[n*n][2]));
	cout<<ans/1000<<" "<<ans%1000;
    return 0;
}