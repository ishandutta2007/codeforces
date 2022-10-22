#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e4+7;
int f[205][205][105],dp[105][2];
char c[205];int n,m,ans;
int SZ;
struct mat{
	int f[305][305];
	mat(){memset(f,0,sizeof(f));}
	mat operator *(const mat o){
		mat ans;
		for(int i=0;i<SZ;i++)for(int j=0;j<SZ;j++){
			ll s=0;
			for(int k=i;k<=j;k++)s+=f[i][k]*o.f[k][j];
			ans.f[i][j]=s%M;
		}
		return ans;
	}
};
mat myp(mat x,int t){
	mat ans;for(int i=0;i<SZ;i++)ans.f[i][i]=1;
	for(;t;t>>=1,x=x*x)if(t&1)ans=ans*x;return ans;
}
void solve0(){
	SZ=n/2+n+1;int T=(n+m+1)/2;mat x;
	x.f[0][0]=25;
	for(int i=1;i<=n/2;i++)x.f[i-1][i]=1,x.f[i][i]=25;
	for(int i=1;i<n;i++)x.f[i+n/2][i+n/2+1]=1,x.f[i+n/2][i+n/2]=24;
	x.f[SZ-1][SZ-1]=26;
	for(int i=0;i<=n/2;i++)x.f[i][n/2+1+2*i]=dp[i][0];
	x=myp(x,T);
	(ans+=x.f[0][SZ-1])%=M;
}
void solve1(){
	SZ=n/2+n+2;int T=(n+m+1)/2+1,mul=1;mat x;
	for(int i=1;i<=n/2;i++)x.f[i-1][i]=1,x.f[i][i]=25;
	for(int i=1;i<=n;i++)x.f[i+n/2][i+n/2+1]=1,x.f[i+n/2][i+n/2]=24;
	x.f[SZ-1][SZ-1]=26;
	for(int i=0;i<=n/2;i++)x.f[i][n/2+1+2*i]=dp[i][1];
	if((n+m)&1)T--,mul=26;
	x=myp(x,T);(ans+=x.f[0][SZ-1]*mul%M)%=M;
}
int main(){
	scanf("%s%d",c+1,&m),n=strlen(c+1);
	f[1][n][0]=1;
	for(int t=n;t;t--)for(int l=1,r=t;r<=n;l++,r++){
		if(l==r){
			for(int k=0;k<=n/2;k++)
				(dp[k][0]+=f[l][r][k])%=M;
			continue;
		}
		if(c[l]==c[r]){
			if(l==r-1){
				for(int k=0;k<=n/2;k++)
					(dp[k+1][1]+=f[l][r][k])%=M;
			}else for(int k=0;k<=n/2;k++)
				(f[l+1][r-1][k+1]+=f[l][r][k])%=M;
			continue;
		}
		for(int k=0;k<=n/2;k++){
			(f[l+1][r][k]+=f[l][r][k])%=M;
			(f[l][r-1][k]+=f[l][r][k])%=M;
		}
	}
	solve0();
	solve1();
	printf("%d",ans);
}