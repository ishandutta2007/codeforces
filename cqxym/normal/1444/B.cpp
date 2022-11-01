#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
#define P 998244353
int a[300000];
inline int PowMod(int x,int y){
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
int main(){
	int n,f1=1,f2=1;
	cin>>n;
	for(R i=0;i!=n<<1;i++){
		cin>>a[i];
	}
	sort(a,a+(n<<1));
	for(R i=1;i<=n;i++){
		f2=(L)f2*i%P;
		f1=(L)f1*(i+n)%P;
	}
	f1=(L)f1*PowMod(f2,P-2)%P;
	int ans=0;
	for(R i=0;i!=n;i++){
		ans+=a[i+n]-a[i];
		if(ans>=P){
			ans-=P;
		}
	}
	cout<<(L)ans*f1%P;
	return 0;
}