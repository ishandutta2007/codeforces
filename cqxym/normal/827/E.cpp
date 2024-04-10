#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define R register int
#define D double
#define I inline
#define N 1048576
#define PIE 3.141592653589793
char s[500001];
struct Complex{
	D Real,Imag;
	I Complex friend operator+(Complex A,Complex B){
		A.Real+=B.Real;
		A.Imag+=B.Imag;
		return A;
	}
	I Complex friend operator-(Complex A,Complex B){
		A.Real-=B.Real;
		A.Imag-=B.Imag;
		return A;
	}
	I Complex friend operator*(Complex A,Complex B){
		Complex C;
		C.Real=A.Real*B.Real-A.Imag*B.Imag;
		C.Imag=A.Real*B.Imag+A.Imag*B.Real;
		return C;
	}
}a[6][N],c[N];
I void Swap(auto&x,auto&y){
	auto t=x;
	x=y;
	y=t;
}
I auto Pair(D x,D y){
	Complex Res;
	Res.Real=x;
	Res.Imag=y;
	return Res;
}
I void FFT(Complex*A,const int len,const int type){
	int tem=0;
	for(R i=0;i!=len;i++){
		if(i<tem){
			Swap(A[i],A[tem]);
		}
		int p=len;
		do{
			p>>=1;
			tem^=p;
		}while(tem<p);
	}
	static Complex w[N];
	w[0]=Pair(1,0);
	for(R i=1;i!=len;i<<=1){
		Complex omg=Pair(cos(PIE/i),sin(PIE/i)*type);
		for(R j=i-2>>1;j!=-1;j--){
			w[j<<1|1]=w[j]*omg;
			w[j<<1]=w[j];
		}
		for(R j=0;j!=len;j+=i<<1){
			for(R k=j;k!=i+j;k++){
				Complex t1=A[k],t2=A[i+k]*w[k-j];
				A[k]=t1+t2;
				A[i+k]=t1-t2;
			}
		}
	}
}
bool vis[500001];
I void Solve(){
	int n,x,len=1;
	scanf("%d",&n);
	while(len<n){
		len<<=1;
	}
	len<<=1;
	scanf("%s",s);
	for(R i=0;i!=6;i++){
		for(R j=n;j!=len;j++){
			a[i][j]=Pair(0,0);
		}
	}
	for(R i=0;i!=n;i++){
		if(s[i]=='?'){
			x=0;
		}else{
			x=s[i]=='V'?1:2;
		}
		a[0][i]=a[5][n-i-1]=Pair(x*x*x,0);
		a[1][i]=Pair(x*x,0);
		a[2][i]=a[3][n-i-1]=Pair(x,0);
		a[4][n-i-1]=Pair(-2*x*x,0);
	}
	for(R i=0;i!=6;i++){
		FFT(a[i],len,1);
	}
	for(R i=0;i!=len;i++){
		c[i]=a[0][i]*a[3][i]+a[1][i]*a[4][i]+a[2][i]*a[5][i];
	}
	FFT(c,len,-1);
	for(R i=0;i!=n;i++){
		long long b=c[i+n].Real+.5;
		vis[i+1]=b==0;
	}
	vector<int>A;
	for(int i=1;i<=n;i++){
		if(vis[i]==true){
			for(R j=i<<1;j<=n;j+=i){
				if(vis[j]==false){
					goto Fail;
				}
			}
			A.push_back(i);
		}
		Fail:;
	}
	printf("%d\n",A.size());
	for(int T:A){
		printf("%d ",T);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}