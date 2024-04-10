#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a,b,t,u=1000001;
main(){
	cin>>n>>m>>i>>j>>a>>b;
	int bx[]={1,n,n,1};
	int by[]={m,1,m,1};
	for(t=0;t<4;t++){
		if(abs(bx[t]-i)%a==0 && abs(by[t]-j)%b==0){
			int l=abs(bx[t]-i)/a;
			int m=abs(by[t]-j)/b;
			if((l-m)%2==0)u=min(max(l,m),u);
		}
	}
	if(u==1000001||(u!=0&&(n<=a||m<=b)))cout<<"Poor Inna and pony!";
	else cout<<u;
}