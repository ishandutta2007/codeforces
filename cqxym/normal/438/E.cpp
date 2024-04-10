#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 262144
#define P 998244353
int c[N],b[N];
I void Swap(int&x,int&y){
	int tem=x;
	x=y;
	y=tem;
}
I int Add(int x,int y){
	x+=y;
	return x>=P?x-P:x;
}
I int Div2(int x){
	return((x&1)==1?x+P:x)>>1;
}
I int PowMod(int x,int y){
	int s=1;
	while(y!=0){
		if((y&1)==1){
			s=(L)s*x%P;
		}
		x=(L)x*x%P;
		y>>=1;
	}
	return s;
}
I void NTT(int*A,int len,const short type){
	int tem=0;
	for(R i=0;i!=len;i++){
		if(i<tem){
			Swap(A[i],A[tem]);
		}
		R j=len;
		do{
			j>>=1;
			tem^=j;
		}while(tem<j);
	}
	static int w[N];
	w[0]=1;
	for(R i=1;i!=len;i<<=1){
		tem=i<<1;
		int omg=PowMod(3,P-1+(P-1)*type/tem);
		for(R j=1;j!=i;j++){
			w[j]=(L)w[j-1]*omg%P;
		}
		for(R j=0;j!=len;j+=tem){
			for(R k=j;k!=i+j;k++){
				int t1=A[k],t2=(L)A[i+k]*w[k-j]%P;
				A[k]=Add(t1,t2);
				A[i+k]=Add(t1,P-t2);
			}
		}
	}
	if(type==-1){
		tem=PowMod(len,P-2);
		for(R i=0;i!=len;i++){
			A[i]=(L)A[i]*tem%P;
		}
	}
}
I void PolyInverse(int*A,int*B,const int len){
	static int tem[N];
	B[0]=PowMod(A[0],P-2);
	for(R i=1;i!=len;i<<=1){
		int p=i<<2;
		NTT(B,p,1);
		for(R j=0;j!=i<<1;j++){
			tem[j]=A[j];
		}
		NTT(tem,p,1);
		for(R j=0;j!=p;j++){
			B[j]=(P+2-(L)tem[j]*B[j]%P)*B[j]%P;
		}
		NTT(B,p,-1);
		for(R j=i<<1;j!=p;j++){
			B[j]=tem[j]=0;
		}
	}
	for(R i=0;i!=len<<1;i++){
		tem[i]=0;
	}
}
I void PolySqrt(int*A,int*B,const int len){
	static int C[N],D[N];
	B[0]=1;
	for(R i=1;i!=len;i<<=1){
		for(R j=0;j!=i<<1;j++){
			C[j]=A[j];
			D[j]=0;
		}
		for(R j=i<<1;j!=i<<2;j++){
			D[j]=C[j]=0;
		}
		NTT(C,i<<2,1);
		PolyInverse(B,D,i<<1);
		NTT(B,i<<2,1);
		NTT(D,i<<2,1);
		for(R j=0;j!=i<<2;j++){
			B[j]=Div2(((L)C[j]*D[j]+B[j])%P);
		}
		NTT(B,i<<2,-1);
		for(R j=i<<1;j!=i<<2;j++){
			B[j]=0;
		}
	}
}
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		c[x]=P-4;
	}
	c[0]=1;
	x=1;
	while(x<=m){
		x<<=1;
	}
	PolySqrt(c,b,x);
	b[0]=2;
	for(R i=0;i!=x;i++){
		c[i]=0;
	}
	PolyInverse(b,c,x);
	for(R i=1;i<=m;i++){
		x=c[i]<<1;
		printf("%d\n",x>=P?x-P:x);
	}
	return 0;
}