#include <iostream>
#include <cstdio>
using namespace std;
int n,m,_n,_m,x,ans=1;
int ask(int opt,int size,int MX){
	for (int i=size;i<MX;i*=2){
		if (opt==1)cout<<'?'<<' '<<_n<<' '<<min(i,MX-i)<<' '<<1<<' '<<1<<' '<<1<<' '<<i+1<<endl;
		if (opt==2)cout<<'?'<<' '<<min(i,MX-i)<<' '<<_m<<' '<<1<<' '<<1<<' '<<i+1<<' '<<1<<endl;
		cin>>x;
		if (x==0)return 0;
	}
	return 1;
}
inline void calc(int n,int _n,int fg){
	for (int i=2;i<=n;i++){
		int val=1,now=1;
		while(n%i==0)n/=i,val*=i;
		for (int j=val/i;j>=1;j/=i)
			if (ask(fg,_n/val*j,_n/val*j*i))now++;
			else break;
		ans*=now;
	}
	return;
}
int main(){
	cin>>n>>m;
	_n=n,_m=m;
	calc(n,n,2);
	calc(m,m,1);
	cout<<"! "<<ans<<endl;
	return 0;
}