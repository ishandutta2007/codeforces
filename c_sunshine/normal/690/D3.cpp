#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
typedef int MAT[105][105];
const int M=1000003;
int C,W,H;
LL temp[105][105];

void mult(MAT &a,MAT &b,MAT &c)
{
	register int i,j,k;
	for(i=0;i<=W;i++)
		for(j=0;j<=W;j++)
		{
			temp[i][j]=0;
			for(k=0;k<=W;k++)
				temp[i][j]+=(LL)a[i][k]*b[k][j];
		}
	for(i=0;i<=W;i++)
		for(j=0;j<=W;j++)
			c[i][j]=temp[i][j]%M;
}
MAT A,X;

int main()
{
	//f[i]=\sum f[i-j-1] H^j [1<=j<=W]
	cin>>C>>W>>H;
	for(int i=0;i<=W;i++)
		X[i][0]++,X[i][i+1]+=H;
	for(int i=0;i<=W;i++)
		A[i][i]=1;
	int b=C;
	for(;b;b>>=1,mult(X,X,X))
		if(b&1)
			mult(A,X,A);
	int ans=0;
	for(int i=0;i<=W;i++)
		ans=(ans+A[0][i])%M;
	cout<<ans<<endl;
	return 0;
}