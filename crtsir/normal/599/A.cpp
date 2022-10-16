#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int d1,d2,d3;
	cin>>d1>>d2>>d3;
	cout<<(d1+d2+d3-max(d1,max(d2,d3)))*2+d1+d2+d3-max((d1+d2+d3-max(d1,max(d2,d3)))*2,d1+d2+d3);
}