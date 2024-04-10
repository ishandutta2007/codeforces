#include<iostream>
using namespace std;
#define R register int
#define I inline void
I Min(int&x,const int y){
	if(x>y){
		x=y;
	}
}
int f[10001],g[10001],a[100],b[100];
I Clear(int*A,int n){
	n*=100;
	for(R i=0;i<=n;i++){
		A[i]=999999999;
	}
}
I Solve(){
	int n,sum=0,sum2=0,ans=999999999;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	Clear(f,n);
	f[0]=0;
	for(R i=0;i!=n;i++){
		cin>>b[i];
		Clear(g,n);
		for(R j=i*100;j!=-1;j--){
			Min(g[j+a[i]],f[j]+a[i]*j+b[i]*(sum-j));
			Min(g[j+b[i]],f[j]+a[i]*(sum-j)+b[i]*j);
		}
		for(R j=(i+1)*100;j!=-1;j--){
			f[j]=g[j];
		}
		sum+=a[i]+b[i];
		sum2+=a[i]*a[i]+b[i]*b[i];
	}
	for(R i=100*n;i!=-1;i--){
		Min(ans,f[i]);
	}
	cout<<(ans<<1)+sum2*(n-1)<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}