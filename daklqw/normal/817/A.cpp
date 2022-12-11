#include <iostream>
using namespace std;
int n,m,x,y,a,b,s;
int main(){
	cin>>n>>m>>x>>y>>a>>b;
	x-=n,y-=m;if(x%a|y%b)s=1;
	else{x/=a,y/=b;s=(x^y)&1;}
	cout<<(s?"NO":"YES")<<endl;
	return 0;
}