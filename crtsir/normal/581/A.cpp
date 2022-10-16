#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<a+b-max(a,b)<<' '<<(max(a,b)*2-a-b)/2;
}