#include<cstdio>
#include<algorithm>
using namespace std; 
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 131072
#define MOD 998244353
int N,R[MN*2+5],w[2][MN*2+5],x[MN*2+5],y[MN*2+5];
struct pol
{
	int n,*x;
	pol(int n):n(n),x(new int[n]){}
	int operator()(int z)const{return z<n?x[z]:0;}
};
inline int pw(int x,int y)
{
	int r=1;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r; 
}
void init(int n)
{
	for(N=1;N<n;N<<=1);
	int i,j,k,g=pw(3,(MOD-1)/N);
	for(w[0][0]=i=1;i<N;++i)w[0][i]=1LL*w[0][i-1]*g%MOD;
	for(w[1][0]=i=1;i<N;++i)w[1][i]=w[0][N-i];
	for(i=j=0;i<N;R[++i]=j)for(k=N>>1;(j^=k)<k;k>>=1);
}
inline int mod(int x){return x<MOD?x:x-MOD;}
void fft(int*x,int v)
{
	int i,j,k,p;
	for(i=0;i<N;++i)if(i<R[i])swap(x[i],x[R[i]]);
	for(i=1;i<N;i<<=1)for(j=0;j<N;j+=i<<1)for(k=0;k<i;++k)
	{
		p=1LL*x[i+j+k]*w[v][N/(i<<1)*k]%MOD;
		x[i+j+k]=mod(x[j+k]+MOD-p);x[j+k]=mod(x[j+k]+p);
	}
	if(v)for(p=pw(N,MOD-2),i=0;i<N;++i)x[i]=1LL*x[i]*p%MOD;
}
void inv(const pol&A)
{
	if(A.n<2){A.x[0]=pw(A.x[0],MOD-2);return;}
	pol B(A.n>>1);int i;
	for(i=0;i<B.n;++i)B.x[i]=A.x[i];inv(B);
	init(A.n+B.n-1);
	for(i=0;i<N;++i)x[i]=A(i),y[i]=B(i);
	fft(x,0);fft(y,0);
	for(i=0;i<N;++i)x[i]=y[i]*(2+MOD-1LL*x[i]*y[i]%MOD)%MOD;
	fft(x,1);for(i=0;i<A.n;++i)A.x[i]=x[i];
}
void sqrt(const pol&A)
{
	if(A.n<2)return;
	pol B(A.n>>1),C(A.n);int i;
	for(i=0;i<B.n;++i)B.x[i]=A.x[i];sqrt(B);
	for(i=0;i<C.n;++i)C.x[i]=B(i);inv(C);
	init(A.n+C.n-1);
	for(i=0;i<N;++i)x[i]=A(i),y[i]=C(i);
	fft(x,0);fft(y,0);
	for(i=0;i<N;++i)x[i]=1LL*x[i]*y[i]%MOD;
	fft(x,1);for(i=0;i<A.n;++i)A.x[i]=(MOD+1LL)/2*(B(i)+x[i])%MOD;
}
int main()
{
	int n,m,i;pol A(MN);
	n=read();m=read();
	for(A.x[0]=1;n--;)A.x[read()]=MOD-4;
	sqrt(A);A.x[0]=(A.x[0]+1)%MOD;inv(A);
	for(i=1;i<=m;++i)printf("%d\n",2*A.x[i]%MOD);
}