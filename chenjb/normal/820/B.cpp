#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,a;
	cin>>n>>a;
	int base=n*a/180;
	base=max(1,min(n-2,base));
	int bk=base;
	for(int ck=max(1,base-2);ck<=min(n-2,base+2);ck++)
		if(abs(180*ck-n*a)<abs(180*bk-n*a))bk=ck;
	cout<<2<<" "<<1<<" "<<bk+2<<endl;
	return 0;
}