#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
using namespace std;
inline int Qpow(int a,int p){
	if (p==0)return 1;
	a%=mod;
	register int ans=Qpow(a,p/2);
	ans=ans*ans%mod;
	if (p%2==1)ans=ans*a%mod;
	return ans;
}
inline int inv(register int x){
	return Qpow(x,mod-2);
}
struct Mat{
	int n,m,mat[105][105];
	Mat(){
		n=m=0;
		memset(mat,0,sizeof(mat));
		return;
	}
	Mat operator *(const Mat &x)const{
		Mat ans;
		ans.n=n,ans.m=x.m;
		for (register int i=1;i<=ans.n;i++)
			for (register int j=1;j<=ans.m;j++)
				for (register int k=1;k<=m;k++)
					ans.mat[i][j]=(ans.mat[i][j]+mat[i][k]*x.mat[k][j])%mod;
		return ans;
	}
}f,c;
inline Mat Qpow(Mat a,int p){
	if (p==1)return a;
	Mat ans=Qpow(a,p/2);
	ans=ans*ans;
	if (p%2==1)ans=ans*a;
	return ans;
}
int n,k,a[105],n0,num,x[105],y[105],z[105];
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0)n0++;
	}
	for (int i=1;i<=n0;i++)
		if (a[i]==0)num++;
	if (n0==n||n0==0){
		cout<<1<<endl;
		return 0;
	}
	for (register int i=0;i<=n0;i++)
		if (n-n0>=n0-i)x[i]=((n0-i)*(n-2*n0+2*i)+(n0*(n0-1)/2%mod)+(n-n0)*(n-n0-1)/2)%mod*inv(n*(n-1)/2)%mod,y[i]=(n0-i)*(n0-i)%mod*inv(n*(n-1)/2)%mod,z[i]=i*(n-2*n0+i)%mod*inv(n*(n-1)/2)%mod;
	f.n=n0+1,f.m=1;
	f.mat[num+1][1]=1;
	c.n=c.m=n0+1;
	for (register int i=0;i<=n0;i++){
		c.mat[i+1][i+1]=x[i];
		if (i>0)c.mat[i+1][i]=y[i-1];
		if (i<n0)c.mat[i+1][i+2]=z[i+1];
	}
	f=Qpow(c,k)*f;
	cout<<f.mat[n0+1][1]<<endl; 
	return 0;
}