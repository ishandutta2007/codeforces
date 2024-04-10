#include <iostream>
#include <cstdio>
#include <cstring> 
#define mod 1000000007
#define int long long
using namespace std;
int n,m;
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
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=x.m;j++)
				for (register int k=1;k<=m;k++)
					ans.mat[i][j]=(ans.mat[i][j]+mat[i][k]*x.mat[k][j])%mod;
		return ans;
	}
}a,b,ans;
inline Mat Qpow(Mat a,int p){
	Mat ans;
	ans.n=a.n,ans.m=a.m;
	if (p==0){
		for (register int i=1;i<=ans.n;i++)
			ans.mat[i][i]=1;
		return ans;
	}
	ans=Qpow(a,p/2);
	ans=ans*ans;
	if (p%2)ans=ans*a;
	return ans;
}
signed main(){
	cin>>n>>m;
	a.n=a.m=m;
	for (int i=1;i<m;i++)
		a.mat[i][i+1]=1;
	a.mat[m][1]=a.mat[m][m]=1;
	b.n=m,b.m=1;
	for (int i=1;i<=m;i++)b.mat[i][1]=1;
	ans=Qpow(a,n)*b;
	cout<<ans.mat[1][1]<<endl;
	return 0;
}