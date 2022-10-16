#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,f=0;
	cin>>a>>b;
	char x;
	for(int i=0;i<a*b;i++)
	{
		cin>>x;
		if(x=='C'||x=='M'||x=='Y')
			f=1;
	}
	if(f==1)
	{
		cout<<"#Color";
		return 0;
	}
	cout<<"#Black&White";
}