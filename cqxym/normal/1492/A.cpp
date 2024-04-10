#include<iostream>
using namespace std;
#define R register int
#define L long long
inline L Calc(L p,L a){
	p%=a;
	if(p==0){
		return 0;
	}
	return a-p;
}
int main(){
	L t,p,a,b,c;
	cin>>t;
	for(R i=0;i!=t;i++){
		cin>>p>>a>>b>>c;
		cout<<min(min(Calc(p,a),Calc(p,b)),Calc(p,c))<<endl;
	}
	return 0;
}