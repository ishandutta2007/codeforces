#include<iostream>
using namespace std;
int f(int d){
	int cnt=0,res;
	for(int i=d;i<=200;i+=d) for(int j=1;j<=200;++j) ++cnt;
	cout<<"? "<<cnt<<"\n";
	for(int i=d;i<=200;i+=d) for(int j=1;j<=200;++j) cout<<i<<" "<<j<<"\n";
	cout.flush();cin>>res;
	return res;
}
int F[9],l,r,md,b,h;
int main(){
	F[0]=f(1);
	for(l=1,r=8;l<r;){
		md=l+r>>1;
		if((F[md]=f(1<<md))*(1<<md)==F[0]) l=md+1;
		else r=md;
	}
	h=abs(2*F[l]-F[0]/(1<<(l-1)))-1;
	b=F[0]/(h+1)-1;
	cout<<"! "<<2*(b+h)<<endl;
	return 0;
}