#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k;
long long wa(long long u,long long t){
	//human = u, power = t
	if(t>=u){return (t*(t+1)/2)-((t-u)*(t-u+1)/2);}
	return (t*(t+1)/2)+(u-t);
}
long long solve(long long r,long long p){
	long long A1=wa(p,r);
	long long A2=wa(n-p,max(1LL,r-1));
	//cout<<A1<<"-"<<p<<"-"<<r<<' '<<A2<<"-"<<n-p<<"-"<<max(1LL,r-1)<<" ";
	return A1+A2;
}
int main(){
	long long L=0,R=(1LL<<30),M;cin>>n>>m>>k;
	while(true){
		M=(L+R)/2;
		long long H1=solve(M,k),H2=solve(M+1,k);
		//cout<<M<<' '<<H1<<endl;
		if(H1<=m && H2>m){cout<<M<<endl;break;}
		if(H1>m)R=M;
		else L=M;
	}
	return 0;
}