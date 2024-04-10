#include<iostream>
using namespace std;
#define R register int
inline void Add(int&x,const int y,const int P){
	x+=y;
	if(x>=P){
		x-=P;
	}
}
int f[4000001];
int main(){
	f[1]=1;
	int n,P;
	cin>>n>>P;
	f[2]=P-1;
	for(R i=1;i<=n;i++){
		Add(f[i],f[i-1],P);
		if(i!=n){
			Add(f[i+1],f[i],P);
			for(R j=2;j<=n;j++){
				int lf=j*i,rt=j*(i+1);
				if(lf>n){
					break;
				}
				Add(f[lf],f[i],P);
				if(rt<=n){
					Add(f[rt],P-f[i],P);
				}
			}
		}
	}
	cout<<f[n];
	return 0;
}