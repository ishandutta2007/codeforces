#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string a,b,c,d;
int n,i;

int main()
{
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	scanf("%d",&n);

	for(;n--;){
		cin>>c>>d;
		if(a==c) a=d;
		else b=d;
		cout<<a<<" "<<b<<endl;
	}
	
	return 0;
}