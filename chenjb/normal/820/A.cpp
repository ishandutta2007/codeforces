#include <iostream>
using namespace std;
int main()
{
	int c,v0,v1,a,l;
	cin>>c>>v0>>v1>>a>>l;
	for(int i=1;;i++)
	{
		if (i!=1)c+=l;
		int v=min(v1,v0+(i-1)*a);
		c-=v;
		if (c<=0)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}