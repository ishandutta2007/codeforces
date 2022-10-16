#include <iostream>
#include <cstdio> 
using namespace std;
long long r,x,y;
int main(){
///	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>r;
	for (x=1;x*x<r;x++){
		y=(r-x*x-x-1)/(2*x);
		if (x*x+2*x*y+x+1==r&&y!=0){
			cout<<x<<' '<<y<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}