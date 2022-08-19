#include <iostream>
using namespace std;
int main(){
	int lx,ly,rx,ry,p;
	long long x=0,y=0;
	cin>>lx>>rx;
	for(int k=0;k<lx;k++){
		cin>>p;
		x=x*rx+p;
	}
	cin>>ly>>ry;
	for(int k=0;k<ly;k++){
		cin>>p;
		y=y*ry+p;
	}
	if(x>y)cout<<'>';
	if(x==y)cout<<'=';
	if(x<y)cout<<'<';
	return 0;
}