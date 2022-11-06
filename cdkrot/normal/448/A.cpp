#include <iostream>
#include <stdint.h>
//#include <tgmath.h>

using std::cin; using std::cout; using std::endl;

int ceil(int a, int b)
{
	return a/b+((a%b==0)?0:1);
}

int main()
{
	int a1,a2,a3,b1,b2,b3,n;
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
	int N=ceil((a1+a2+a3),5)+ceil((b1+b2+b3),10);
	if (N<=n)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}