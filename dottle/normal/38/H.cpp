#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define lxl long long
const int N=52;
using namespace std;
struct num{int x;num(){cin>>x;}operator int(){return x;}};

lxl dp[N][N][N];
int f[N][N],A[N],B[N],C[N];
int n,m;
int mx[N],mn[N],g1,g2,s1,s2;

lxl solve(int l,int r,int L,int R){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		A[i]=B[i]=C[i]=0;
		for(int j=1;j<=n;j++)
			if(i!=j)
				A[i]|=f[i][j]<=l,
				B[i]|=f[i][j]>L&&f[i][j]<R,
				C[i]|=f[i][j]>=r;	
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;j+k<=i;k++)
				if(dp[i][j][k]){
					if(A[i+1])
						dp[i+1][j+1][k]+=dp[i][j][k];
					if(B[i+1])
						dp[i+1][j][k+1]+=dp[i][j][k];
					if(C[i+1])
						dp[i+1][j][k]+=dp[i][j][k];
				}
	lxl sum=0;
	for(int i=g1;i<=g2;i++)
		for(int j=s1;j<=s2;j++)
			sum+=dp[n][i][j];
	return sum;
}

lxl calc(int l,int r){
	return solve(l,r,l,r)-solve(l,r+1,l,r)-solve(l-1,r,l,r)+solve(l-1,r+1,l,r);
}

signed main(){
	cin>>n>>m;
	memset(f,1,sizeof(f));
	for(int i=1;i<=m;i++){
		num x,y,z;
		f[x][y]=f[y][x]=z;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[i][j]<<8|i;
	for(int i=1;i<=n;i++){
		mx[i]=0,mn[i]=1e9;
		for(int j=1;j<=n;j++)
			if(i!=j)
				mx[i]=max(mx[i],f[i][j]),
				mn[i]=min(mn[i],f[i][j]);
	}
	cin>>g1>>g2>>s1>>s2;
	lxl ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=calc(mn[i],mx[j]);
	cout<<ans<<endl;
}