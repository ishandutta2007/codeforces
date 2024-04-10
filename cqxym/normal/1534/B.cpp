#include<iostream>
using namespace std;
#define R register int
#define I inline
I int Max(const int x,const int y){
	return x>y?x:y;
}
I int Abs(int x,const int y){
	x-=y;
	return x<0?-x:x;
}
int a[400002];
I void Solve(){
	int n,x;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=0;
	long long ans=0;
	for(R i=1;i<=n;i++){
		x=Max(a[i-1],a[i+1]);
		if(a[i]>x){
			ans+=a[i]-x;
			a[i]=x;
		}
	}
	ans+=a[1];
	for(R i=1;i<=n;i++){
		ans+=Abs(a[i],a[i+1]);
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}