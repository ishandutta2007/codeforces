#include<iostream> 
#include<cmath>
using namespace std;
bool pri(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(!(x%i))
			return false;
	return true; 
}
int main()
{
	int a,b,no=0,p1=2,p2=3;
	cin>>a>>b;
	while(p1+p2+1<=a)
	{
		if(pri(p1+p2+1))
			no++;
		int i;
		for(i=p2+1;!pri(i);i++);
		p1=p2;
		p2=i;
	}
	cout<<(no>=b?"YES":"NO"); 
	return 0;
}
/*1
27 2
*/
/*2
45 7
*/