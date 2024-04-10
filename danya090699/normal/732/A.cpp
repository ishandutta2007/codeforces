#include <iostream>
using namespace std;
int main()
{
	int k, r, an;
	cin>>k>>r;
	for(int a=1; a<=10; a++)
	{
		if(((k*a)%10==r)or((k*a)%10==0))
		{
			an=a;
			break;
		}
	}
	cout<<an;
}