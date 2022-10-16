#include<iostream>
#include<algorithm>
using namespace std;
void ap(int a1,int a2,int a3,int a4){
	if(a1<a2)
	{
		swap(a1,a2);
		swap(a3,a4);
	}
	if(a1==a2&&a3>a4)
	{
		swap(a1,a2);
		swap(a3,a4);
	}
}
int main()
{
	int a,b;
	cin>>a>>b;
	int x[a],y[a],z[a];
	for(int i=0;i<a;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<a;i++)
		z[i]=x[i]*100-y[i];
	int c=0;
	sort(z,z+a);
	for(int i=0;i<a;i++)
		if(z[i]==z[a-b])
			c++;
	cout<<c;
}