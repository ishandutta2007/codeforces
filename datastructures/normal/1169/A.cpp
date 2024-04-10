#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int c[105],n,a,b,x,y;
signed main(){
	cin>>n>>a>>b>>x>>y;
	for (int t=1;t<=n;t++){
		if (a==x){
			cout<<"YES"<<endl;
			return 0;
		}
		if (a==b||x==y)break;
		a++,x--;
		if (a>n)a=1;
		if (x<1)x=n;
	} 
	cout<<"NO"<<endl;
	return 0;
}