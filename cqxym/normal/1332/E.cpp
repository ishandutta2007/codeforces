#include<stdio.h>
#define R register int
#define L long long
#define P 998244353
typedef int Matrix[2][2];
inline void Mul(Matrix A,Matrix B){
	Matrix C;
	for(R i=0;i!=2;i++){
		for(R j=0;j!=2;j++){
			C[i][j]=0;
		}
	}
	for(R i=0;i!=2;i++){
		for(R j=0;j!=2;j++){
			for(R k=0;k!=2;k++){
				C[i][k]=((L)A[i][j]*B[j][k]+C[i][k])%P;
			}
		}
	}
	for(R i=0;i!=2;i++){
		for(R j=0;j!=2;j++){
			A[i][j]=C[i][j];
		}
	}
}
int main(){
	int n,m,l,r,a0,a1;
	scanf("%d%d%d%d",&n,&m,&l,&r);
	L t=(L)n*m-1;
	a0=(r>>1)-(l-1>>1);
	a1=(r+1>>1)-(l>>1);
	Matrix A,S;
	S[0][0]=S[1][1]=1;
	S[0][1]=S[1][0]=0;
	A[0][0]=A[1][1]=a0;
	A[1][0]=A[0][1]=a1;
	while(t!=0){
		if((t&1)==1){
			Mul(S,A);
		}
		t>>=1;
		Mul(A,A);
	}
	int ans=((L)a0*S[0][0]+(L)a1*S[1][0])%P;
	if((n&m&1)==1){
		ans=((L)a0*S[0][1]+(L)a1*S[1][1]+ans)%P;
	}
	printf("%d",ans);
	return 0;
}