#include<iostream>
using namespace std;
int main()
{
	long long l1,r1,l2,r2,k,ans;
	cin>>l1>>r1>>l2>>r2>>k;
	if(l1<l2)l1=l2;
	if(r1>r2)r1=r2;
	cout<<(l1<=r1?r1-l1+(k<l1||k>r1):0);
}