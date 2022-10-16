#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x,y,ans=0;
	char a,b;
	cin>>a>>x>>b>>y;
	int z1=a-96,z2=b-96;
	cout<<max(fabs(z1-z2),fabs(x-y))<<endl;
	while(z1!=z2||x!=y)
	{
		if(fabs(z1-1-z2)<fabs(z1-z2))
			cout<<"L",
			z1--;
		if(fabs(z1+1-z2)<fabs(z1-z2))
			cout<<"R",
			z1++;
		if(fabs(x-1-y)<fabs(x-y))
			cout<<"D",
			x--;
		if(fabs(x+1-y)<fabs(x-y))
			cout<<"U",
			x++;
		cout<<endl;
		ans++;
	}
}