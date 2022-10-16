#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef vector<long long> vec;
typedef vector<vec> mat;
mat mul(mat a,mat b){
	mat ret(a.size(),vec(b[0].size()));
	for(long long i=0;i<a.size();i++)
		for(long long k=0;k<b.size();k++)
			for(long long j=0;j<b[0].size();j++)
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%mod;
	return ret;
}
mat mypow(mat x,long long n){
	mat b(x.size(),vec(x.size()));
	for(long long i=0;i<x.size();i++)b[i][i]=1;
	while(n>0){
		if(n&1)b=mul(x,b);
		x=mul(x,x);n>>=1;
	}return b;
}
int main(){
	long long n,m;
	cin>>n>>m;n++;
	mat A(m,vec(m));
	for(int i=1;i<m;i++)
		A[i][i-1]=1;
	A[0][m-1]=1;A[m-1][m-1]=1;
	A=mypow(A,n);
	cout<<A[0][m-1];
}