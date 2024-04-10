#include<iostream>
using namespace std;
#define R register int
inline void Solve(int a,int b,int c,int d){
	cout<<"Yes"<<endl;
	for(R i=0;i!=b;i++){
		cout<<'1';
	}
	for(R i=0;i!=a;i++){
		cout<<'0';
	}
	for(R i=0;i<=d;i++){
		cout<<'1';
	}
	for(R i=0;i!=c;i++){
		cout<<'0';
	}
	cout<<endl;
	for(R i=0;i!=b;i++){
		cout<<'1';
	}
	for(R i=0;i<=a;i++){
		cout<<'0';
	}
	for(R i=0;i!=d;i++){
		cout<<'1';
	}
	for(R i=1;i!=c;i++){
		cout<<'0';
	}
	cout<<'1';
}
int main(){
	int a,b,k;
	cin>>a>>b>>k;
	if(k==0){
		cout<<"Yes";
		for(R i=0;i!=2;i++){
			cout<<endl;
			for(R j=0;j!=b;j++){
				cout<<'1';
			}
			for(R j=0;j!=a;j++){
				cout<<'0';
			}
		}
		return 0;
	}
	if(a==0||b==1){
		cout<<"No";
		return 0;
	}
	if(k>a+b-2){
		cout<<"No";
		return 0;
	}
	if(k<=a){
		Solve(a-k,b-1,k,0);
	}else{
		Solve(0,b-1-k+a,a,k-a);
	}
	return 0;
}