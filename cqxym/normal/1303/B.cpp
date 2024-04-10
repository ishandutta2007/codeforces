#include<iostream>
using namespace std;
#define R register int
#define L long long
inline L Max(L a,L b){
	return a>b?a:b;
}
inline void Solve(){
	L n,p,g,b,d;
	cin>>n>>g>>b;
	p=n+1>>1;
	if(p%g==0){
		d=p/g*(g+b)-b;
	}else{
		d=p/g*(g+b)+p%g;
	}
	cout<<Max(n,d)<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}