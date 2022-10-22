#include<bits/stdc++.h>
using namespace std;
#define N 3000
#define hshmod 10000000
#define mod 1000000007
#define ull unsigned long long
#define pb push_back
bitset<N+1> a;
int dp[N+1][N+2];
inline bool ok(bool a,bool b,bool c,bool d){
	return !(!a&&!b&&c&&d||!a&&b&&!c&&d||a&&b&&c&&!d||a&&b&&c&&d);
}
ull Hsh[N+1],power[N+1];
ull hsh(int l,int r){
	return Hsh[r]-Hsh[l-1]*power[r-l+1];
}
int head[hshmod],nxt[N*N],tot;ull data[N*N];
void add(int x,ull y){
	data[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int main(){
//	freopen("txt.txt","r",stdin);freopen("txt0.txt","w",stdout);
	int n,ans=0,i,j;scanf("%d",&n);
	for(i=1;i<=n;i++){int x;scanf("%d",&x);a[i]=x;}
	power[0]=1;
	for(i=1;i<=n;i++)Hsh[i]=Hsh[i-1]*131ull+a[i]+1,power[i]=power[i-1]*131ull;
	fill(dp[0]+1,dp[0]+n+2,1);
	for(i=1;i<=n;i++)for(j=1;j+i-1<=n;j++)
		dp[i][j]=dp[i-1][j+1],
		dp[i][j]+=i>=2?dp[i-2][j+2]:0,dp[i][j]%=mod,
		dp[i][j]+=i>=3?dp[i-3][j+3]:0,dp[i][j]%=mod,
		dp[i][j]+=i>=4&&ok(a[j],a[j+1],a[j+2],a[j+3])?dp[i-4][j+4]:0,dp[i][j]%=mod;
//	for(i=1;i<=n;i++)for(j=1;j+i-1<=n;j++)
//		printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			ull h=hsh(j,i);
			int hmod=h%hshmod;
//			cout<<h<<" "<<hmod<<" "<<dp[i-j+1][j]<<"\n";
			bool mar=false;
			for(int k=head[hmod];k;k=nxt[k])if(data[k]==h){mar=true;break;}
			if(!mar)ans+=dp[i-j+1][j],ans%=mod,add(hmod,h);
		}
		printf("%d\n",ans);
//		puts("");
	}
	return 0;
}
/*1
3
1
1
1
*/
/*2
5
1
0
1
0
1
*/
/*3
9
1
1
0
0
0
1
1
0
1
*/
/*4
20
1
1
0
0
1
1
0
0
1
1
0
0
1
1
0
0
1
1///
0
0
*/