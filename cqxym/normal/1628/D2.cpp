#include<iostream>
using namespace std;
#define R register int
#define L long long
#define N 1000001
#define P 1000000007
inline int GetInv(int x){
	int y=P-2,res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int fac[N],invf[N],ipw[N];
inline int GetC(int n,int m){
	return(L)fac[n]*invf[m]%P*invf[n-m]%P;
}
inline void Solve(){
	int n,m,k;
	cin>>n>>m>>k;
	if(n==m){
		cout<<(L)n*k%P<<endl;
		return;
	}
	int ans=0;
	for(R i=1;i<=m;i++){
		ans=((L)ipw[n-i]*GetC(n-i-1,m-i)%P*i+ans)%P;
	}
	cout<<(L)ans*k%P<<endl;
}
int main(){
	fac[0]=ipw[0]=1;
	for(R i=1;i!=N;i++){
		fac[i]=(L)fac[i-1]*i%P;
		ipw[i]=((ipw[i-1]&1)==1?ipw[i-1]+P:ipw[i-1])>>1;
	}
	invf[N-1]=GetInv(fac[N-1]);
	for(R i=N-1;i!=0;i--){
		invf[i-1]=(L)invf[i]*i%P;
	}
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}