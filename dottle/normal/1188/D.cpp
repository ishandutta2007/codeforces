#include<bits/stdc++.h>
#define int long long
const int N=500050,P=62;
using namespace std;

int n,mx,A[N],id[N]; 
int k,s[2][N];
int dp[P][N];
bool cmd (int a,int b){
	return (A[a]&((1ll<<k)-1))<(A[b]&((1ll<<k)-1));
}
void gi(int&x,int y){x=min(x,y);}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>A[i],mx=max(mx,A[i]),id[i]=i;
	for(int i=1;i<=n;i++)A[i]=mx-A[i];
	memset(dp,1,sizeof(dp));dp[0][0]=0;
	for(int i=0;i<P-1;i++){
		k=i;
		sort(id+1,id+1+n,cmd);
		for(int j=1;j<=n;j++){
			s[0][j]=s[0][j-1],s[1][j]=s[1][j-1];
			s[A[id[j]]>>i&1][j]++;
		}
		for(int j=0;j<=n;j++){
			int w,up;
			w=s[1][n-j]+s[0][n]-s[0][n-j];
			up=s[1][n]-s[1][n-j];
			gi(dp[k+1][up],dp[k][j]+w);
			w=s[0][n-j]+s[1][n]-s[1][n-j];
			up=n-s[0][n-j];
			gi(dp[k+1][up],dp[k][j]+w);
		}
	}
	cout<<dp[P-1][0]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}