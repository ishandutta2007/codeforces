#include<bits/stdc++.h>
const int N=150,M=N*N;
using namespace std;

int dp[N][M],cnt,a[N];
int S(int n){return n*(n+1)/2;}

void dfs(int l,int r,int k,int d){
	int len=r-l+1;
	if(S(len)==k){
		for(int i=l;i<=r;i++)a[i]=++cnt;
		reverse(a+l,a+r+1);
		return;
	}
	for(int i=2;i<len;i++){
		if(k<=S(i)+len-i||!dp[len-i+1][k-S(i)+1])continue;
		for(int j=l;j<l+i-1;j++)a[j]=++cnt;
		dfs(l+i-1,r,k-S(i)+1,d);
		reverse(a+l,a+r+1);
		return;
	}
	for(int i=4;i<=len;i++) {
		if(!dp[len-i+1][k-i])continue;
		for(int j=r-i+2;j<=r;j+=2)a[j]=++cnt;
		dfs(l,r-i+1,k-i,0);
		for(int j=r-i+3;j<=r;j+=2)a[j]=++cnt;
		if(i&1)swap(a[r-2],a[r]);
		return ;
	}	
}

void solve(){
	int n,k;cin>>n>>k;
	if(dp[n][k])cout<<"YES"<<endl;
	else {
		cout<<"NO"<<endl;
		return ;
	}
	cnt=0;
	dfs(1,n,k,0);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" \n"[i==n];
}

main(){
	ios::sync_with_stdio(false);
	for(int i=0;i<N;i++)dp[i][S(i)]=1;
	for(int i=4;i<N;i++)dp[i][i+1]=1;
	for(int i=2;i<N;i++)
		for(int j=1;j<M;j++)
			if(dp[i][j]){
				for(int k=2;i+k<=N&&j+S(k)<=M;k++)dp[i+k-1][j+S(k)-1]=1;
				for(int k=4;i+k<=N&&j+k<M;k++)dp[i+k-1][j+k]=1;
			}
	int _T=1;cin>>_T;
	while(_T--)solve();
}