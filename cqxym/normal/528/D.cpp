#include<stdio.h>
#include<cmath>
#define R register int
#define L long long
#define I inline
#define N 500000
#define M 1048576
#define P 998244353
char s[N],t[N];
int sum[N],A[M],B[M],C[M];
I int Trans(char c){
	if(c=='A'){
		return 0;
	}
	if(c=='C'){
		return 1;
	}
	return c=='G'?2:3;
}
I int Add(int x,const int y){
	x+=y;
	return x<P?x:x-P;
}
I void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
I int PowMod(int x,int y){
	int res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
I void NTT(int*A,const int len,const short type){
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
	static int w[M];
	w[0]=1;
	for(R i=1;i!=len;i<<=1){
		int omg=PowMod(3,P-1+(P-1)*type/(i<<1));
		for(R j=1;j!=i;j++){
			w[j]=(L)w[j-1]*omg%P;
		}
		for(R j=0;j!=len;j+=i<<1){
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
int main(){
	int n,m,k,ans=0,len=1;
	scanf("%d%d%d\n",&n,&m,&k);
	for(R i=0;i!=n;i++){
		s[i]=getchar();
	}
	getchar();
	for(R i=0;i!=m;i++){
		t[i]=getchar();
	}
	while(len<n+m){
		len<<=1;
	}
	len<<=1;
	for(R i=0;i!=4;i++){
		sum[0]=Trans(s[0])==i;
		for(R j=1;j!=n;j++){
			sum[j]=sum[j-1]+(Trans(s[j])==i);
		}
		for(R j=0;j!=m;j++){
			B[j]=Trans(t[m-j-1])==i;
		}
		for(R j=m;j!=n;j++){
			B[j]=0;
		}
		for(R j=0;j!=n;j++){
			A[j]=sum[j+k<n?j+k:n-1]>(j-k-1<0?0:sum[j-k-1]);
		}
		for(R j=n;j!=len;j++){
			A[j]=B[j]=0;
		}
		NTT(A,len,1);
		NTT(B,len,1);
		for(R j=0;j!=len;j++){
			C[j]=((L)A[j]*B[j]+C[j])%P;
		}
	}
	NTT(C,len,-1);
	for(R i=m-1;i!=n;i++){
		if(C[i]==m){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}