#include<iostream>
using namespace std;
int main(){
	int x=1,y;
	cin>>y;
	while(y>=x*5)
	{
		y=y-5*x;
		x=x*2;
	}
	if(y==0)
	{
		cout<<"Howard";
		return 0;
	}
	if((y-1)/x==0)cout<<"Sheldon";
	if((y-1)/x==1)cout<<"Leonard";
	if((y-1)/x==2)cout<<"Penny";
	if((y-1)/x==3)cout<<"Rajesh";
	if((y-1)/x==4)cout<<"Howard";
}