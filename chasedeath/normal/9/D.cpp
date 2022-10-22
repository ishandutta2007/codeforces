#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=110;
//const ll P=1e9+7;

int n,m,h;
ll dp[N][N][N];
ll C[N][N];


int main(){
	n=rd(),h=rd();
	rep(i,1,100) rep(j,0,i) {
		C[i][j]=1;
		rep(o,1,j) C[i][j]=C[i][j]*(i-o+1)/o;
	}
	//rep(i,1,5) rep(j,1,5) cout<<i<<' '<<j<<' '<<C[i][j]<<endl;
	dp[1][1][1]=1;
	rep(i,2,n) {
		rep(j,1,n) {
			rep(o,1,j) {
				rep(k,1,o*2) if(j+k<=n){
					dp[i][j+k][k]+=dp[i-1][j][o]*C[o*2][k];
				}
			}
		}
	}
	//rep(i,1,n) rep(j,1,n) rep(o,1,n) if(dp[i][j][o]) cout<<i<<' '<<j<<' '<<o<<' '<<dp[i][j][o]<<endl;
	ll ans=0;
	rep(j,h,n) rep(i,1,n) ans+=dp[j][n][i];
	printf("%lld\n",ans);
}