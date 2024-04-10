#include<iostream>
using namespace std;
int main(){
	int x,t=0;
	cin>>x;
	int a[x],b[x],c[x];
	for(int i=0;i<x;i++)
		cin>>a[i]>>b[i];
	c[0]=b[0];
	for(int i=1;i<x;i++)
		if(c[i-1]>b[i])
			c[i]=b[i];
		else
			c[i]=c[i-1];
	for(int i=0;i<x;i++)
		t=t+c[i]*a[i];
	cout<<t;
}