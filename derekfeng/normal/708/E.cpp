#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
int n,m,a,b,p,k;
int f[1504][1504],g[1504],sg[1504];
int s0[1504],s1[1504];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k),p=(ll)a*myp(b,M-2)%M;
	for(int i=0,FC=1,fc=1;i<=m;FC=(ll)FC*(k-i)%M,i++,fc=(ll)fc*i%M)
		g[i]=i<=k?(ll)FC*myp(fc,M-2)%M*myp(p,i)%M*myp(M+1-p,k-i)%M:0;
	sg[0]=g[0];for(int i=1;i<=m;i++)sg[i]=(sg[i-1]+g[i])%M;
	for(int i=1;i<=m;i++)f[1][i]=(ll)sg[i-1]*g[m-i]%M;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			s0[j]=(s0[j-1]+f[i-1][j])%M;
			s1[j]=((ll)s0[j-1]*g[j-1]+s1[j-1])%M;
		}
		for(int j=1;j<=m;j++){
			int all=(ll)s0[m]*g[m-j]%M*sg[j-1]%M;
			int del0=(ll)g[m-j]*sg[j-1]%M*s0[m-j]%M;
			int del1=(ll)g[m-j]*s1[j]%M;
			f[i][j]=(all+M-(del0+del1)%M)%M;
		}
	}
	printf("%d",accumulate(f[n]+1,f[n]+m+1,0ll)%M);
}