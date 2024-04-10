#include<iostream>
using namespace std;
#define R register int
bool vis[200001];
inline void Calc(int x,int y){
	int s=x+y,a,b;
	a=s+1>>1;
	b=s>>1;
	for(R i=0;i<=b;i++){
		int p=a+i-x;
		if(p>-1&&p<=a&&b-i+p==y){
			vis[i+p]=true;
		}
	}
}
inline void Solve(){
	int x,y;
	cin>>x>>y;
	for(R i=0;i<=x+y;i++){
		vis[i]=false;
	}
	Calc(x,y);
	Calc(y,x);
	int ct=0;
	for(R i=0;i<=x+y;i++){
		if(vis[i]==true){
			ct++;
		}
	}
	cout<<ct<<endl;
	for(R i=0;i<=x+y;i++){
		if(vis[i]==true){
			cout<<i<<' ';
		}
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}