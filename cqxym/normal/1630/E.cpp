#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 1000001
#define P 998244353
I int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
I int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int ct[N],f[N],g[N],fac[N],invf[N];
I void Solve(){
	int n,x,gcd,sum;
	scanf("%d",&n);
	gcd=n;
	sum=(L)n*n%P;
	for(R i=1;i<=n;i++){
		ct[i]=f[i]=g[i]=0;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		ct[x]++;
	}
	vector<int>C;
	for(R i=1;i<=n;i++){
		if(ct[i]!=0){
			C.push_back(ct[i]);
			gcd=Gcd(gcd,ct[i]);
			sum=(sum-(L)ct[i]*ct[i])%P;
		}
	}
	if(C.size()==1){
		puts("1");
		return;
	}
	if(sum<0){
		sum+=P;
	}
	for(R i=1;i<=gcd;i++){
		if(gcd%i==0){
			int l=n/i;
			f[l]=fac[l];
			for(int T:C){
				f[l]=(L)f[l]*invf[T/i]%P;
			}
			g[l]=(L)f[l]*sum%P*GetInv((l-1ll)*i%P)%P;
		}
	}
	int a=0,b=0;
	for(R i=1;i<=n;i++){
		int x=Gcd(n,i);
		a+=f[x];
		b+=g[x];
		if(a>=P){
			a-=P;
		}
		if(b>=P){
			b-=P;
		}
	}
	printf("%d\n",(L)b*GetInv(a)%P);
}
int main(){
	fac[0]=1;
	for(R i=1;i!=N;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invf[N-1]=GetInv(fac[N-1]);
	for(R i=N-1;i!=0;i--){
		invf[i-1]=(L)i*invf[i]%P;
	}
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}