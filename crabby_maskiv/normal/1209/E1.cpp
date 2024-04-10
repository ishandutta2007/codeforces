#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const int N=13;
const int M=2005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int dp[N][1<<N];
int a[N][M],c[N][N];
struct node{
	int x[N];
	int mx;
	bool operator <(const node &b)const{
		return mx>b.mx;
	}
}b[M];
int cost,cnt;
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)	
			for(j=1;j<=m;j++)
				cin>>a[i][j];
		memset(b,0,sizeof(b));
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++){
				b[i].mx=max(b[i].mx,a[j][i]);
				b[i].x[j]=a[j][i];
			}
		sort(b+1,b+m+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				c[i][j]=b[i].x[j];
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			for(k=0;k<(1<<n);k++){
				cost=0;
				for(int p1=1;p1<=n;p1++){
					cnt=0;
					for(int p2=0;p2<n;p2++){
						if(!((1<<p2)&k)) continue;
						cnt+=c[i][(p1+p2-1)%n+1];
					}
					cost=max(cost,cnt);
				}
				for(j=0;j<(1<<n);j++){
					if(j&k) continue;
					dp[i][j|k]=max(dp[i][j|k],dp[i-1][j]+cost);
				}
			}
		}
		cout<<dp[n][(1<<n)-1]<<endl;
	}
	return 0;
}