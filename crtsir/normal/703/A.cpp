#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x,a=0,b=0,d,e;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cin>>d>>e;
		if(d>e)
			a++;
		if(d<e)
			b++;
	}
	if(a==b)cout<<"Friendship is magic!^^";
	if(a>b)cout<<"Mishka";
	if(a<b)cout<<"Chris";
}