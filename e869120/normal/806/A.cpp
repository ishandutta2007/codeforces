#include<bits/stdc++.h>
using namespace std;
long long t,x,y,p,q;
bool solve(long long H){
	long long e1=p*H,e2=q*H;
	long long f1=abs(e1-x),f2=abs(e2-y);
	if(e2<y || e1<x || H==0)return false;
	if(f1>f2)return false;
	return true;
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>y>>p>>q;
		long long F=__gcd(p,q);
		p/=F;q/=F;
		long long L=1,R=1000000005,M;
		while(true){
			M=(L+R)/2;
			bool p1=solve(M-1),p2=solve(M);
			if(p1==false && p2==true){
				cout<<M*q-y<<endl;break;
			}
			if(p1==true)R=M;else L=M;
			if(M>=1000000002){cout<<"-1"<<endl;break;}
		}
	}
	return 0;
}