// Problem: CF618G Combining Slimes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF618G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Author: Juruo_cjl
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int M=50;
int n;double p;
double a[M+1][M+1],b[M+1][M+1];
double f[M+1][M+1];
struct matrix{
	double num[M+1][M+1];
	matrix(){memset(num,0,sizeof num);}
	double*operator[](const int x){return num[x];}
	friend matrix operator*(matrix A,matrix B){
		matrix C;
		for(int i=0;i<=M;i++)
			for(int j=0;j<=M;j++)
				for(int k=0;k<=M;k++)
					C[i][j]+=A[i][k]*B[k][j];
		return C;
	}
}s,res;
signed main(){
	read(n,p);p/=1e9;
	for(int i=1;i<=M;i++){
		a[i][1]=p;a[i][2]=1-p;b[i][2]=1-p;
		for(int j=2;j<=M;j++)
			a[i][j]+=a[i][j-1]*a[i-1][j-1],
			b[i][j]+=b[i][j-1]*a[i-1][j-1];
	}
	for(int i=M;i;i--)
		for(int j=1;j<=M;j++)
			a[i][j]=a[i][j]*(1-a[i-1][j]),
			b[i][j]=b[i][j]*(1-a[i-1][j]);
	f[1][1]=1;f[1][2]=2;
	for(int i=2;i<=M;i++){
		for(int j=2;j<=M;j++){
			double sm=0;
			for(int k=1;k<j;k++)
				sm+=a[i-1][k],f[i][j]+=f[i-1][k]*a[i-1][k];
			f[i][j]/=sm;f[i][j]+=j;
		}
		double sm=0;
		for(int k=2;k<=M;k++)
			sm+=b[i-1][k],f[i][1]+=f[i-1][k]*b[i-1][k];
		f[i][1]/=sm;f[i][1]+=1;
	}
	if(n<M){
		double ans=0;
		for(int i=1;i<=n+1;i++)
			ans+=f[n][i]*a[n][i];
		return printf("%.12lf",ans),0;
	}
	res[0][0]=s[0][0]=1;
	for(int j=2;j<=M;j++){
		double sm=0;
		for(int k=1;k<j;k++)
			sm+=a[M][k];
		for(int k=1;k<j;k++)
			s[k][j]=a[M][k]/sm;
		s[0][j]=j;
	}
	double sm=0;
	for(int k=2;k<=M;k++)
		sm+=b[M][k];
	for(int k=2;k<=M;k++)
		s[k][1]=b[M][k]/sm;
	s[0][1]=1;
	for(int i=1;i<=M;i++)res[0][i]=f[M][i];
	int b=n-M;
	while(b){
		if(b&1)res=res*s;
		s=s*s;b>>=1;
	}
	double ans=0;
	for(int i=1;i<=M;i++)
		ans+=res[0][i]*a[M][i];
	return printf("%.12lf",ans),0;
}