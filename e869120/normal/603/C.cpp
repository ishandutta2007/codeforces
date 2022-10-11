#include<iostream>
using namespace std;
int n,a,b,c,d[5]={0,1,0,1,2};
int solve(int pos){
	if(pos<=4)return d[pos];
	if(pos%2==1)return 0;
	if(solve(pos/2)!=1)return 1;
	return 2;
}
int main(){
	cin>>n>>a;a%=2;
	for(int i=0;i<n;i++){
		cin>>b;
		if(a==0){if(b==1 || (b%2==0 && b!=2))c^=1;else if(b==2)c^=2;}
		if(a==1){c^=solve(b);}
	}
	if(c!=0)cout<<"Kevin"<<endl;
	else cout<<"Nicky"<<endl;
	return 0;
}