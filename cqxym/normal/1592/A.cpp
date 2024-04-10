#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,h,x=0,y=0,a;
	cin>>n>>h;
	for(R i=1;i<=n;i++){
		cin>>a;
		if(a>x){
			y=x;
			x=a;
		}else if(a>y){
			y=a;
		}
	}
	a=h/(x+y)<<1;
	h%=x+y;
	if(h>0){
		a++;
	}
	if(h>x){
		a++;
	}
	cout<<a<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}