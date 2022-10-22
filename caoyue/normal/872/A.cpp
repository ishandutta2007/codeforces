#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
int n,m;
int a[10],b[10];
int main(){
	cin>>n>>m;
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	int minn=10;
	rep(i,n){
		rep(j,m){
			if(a[i]==b[j]&&a[i]<minn)minn=a[i];
		}
	}
	if(minn<10){
		cout<<minn<<endl;
		return 0;
	}
	int min1=10,min2=10;
	rep(i,n)min1=min(min1,a[i]);
	rep(i,m)min2=min(min2,b[i]);
	if(min1>min2)cout<<min2<<min1<<endl;
	else cout<<min1<<min2<<endl;
	return 0;
}