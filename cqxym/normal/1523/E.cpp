#include<iostream>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 100001
#define P 1000000007
int fac[N],invf[N];
I int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		x=(L)x*x%P;
		y>>=1;
	}
	return res;
}
I int GetC(int n,int m){
	return(L)fac[n]*invf[m]%P*invf[n-m]%P;
}
I void Solve(){
	int n,m,ans=1;
	cin>>n>>m;
	m--;
	for(R i=1;i<=n;i++){
		if((i-1ll)*m+i<=n){
			ans=((L)GetC(n-(i-1)*m,i)*GetInv(GetC(n,i))+ans)%P;
		}
	}
	cout<<ans<<endl;
}
int main(){
	fac[0]=1;
	for(R i=1;i!=N;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invf[N-1]=GetInv(fac[N-1]);
	for(R i=N-2;i!=-1;i--){
		invf[i]=(1ll+i)*invf[i+1]%P;
	}
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}