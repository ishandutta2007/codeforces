#include<bits/stdc++.h>
using namespace std;
int T,a[4],x,y,xx,xy,yx,yy;
int main(){
	cin>>T;
	while(T--){
		cin>>a[0]>>a[1]>>a[2]>>a[3]>>x>>y>>xx>>xy>>yx>>yy;
		a[0]=-a[0];a[2]=-a[2];
		if(a[0]+a[1]+x>yx||a[0]+a[1]+x<xx){cout<<"No\n";continue;}
		if(a[2]+a[3]+y>yy||a[2]+a[3]+y<xy){cout<<"No\n";continue;}
		if((a[0]||a[1])&&xx==yx){cout<<"No\n";continue;}
		if((a[2]||a[3])&&xy==yy){cout<<"No\n";continue;}
		cout<<"Yes\n";
	}
}