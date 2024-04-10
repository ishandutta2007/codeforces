#include<bits/stdc++.h>  
using namespace std;    
bool pd(int a)
{
	while(a!=0)
	{
		if(a%10!=7&&a%10!=4)
			return false;
		a=a/10;
	}
	return true;
}
int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
		if(a%i==0&&pd(i))
		{
			cout<<"YES";
			return 0;
		}
	cout<<"NO";
}