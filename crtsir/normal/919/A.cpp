#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double a[5000],b[5000],c[5000];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
		c[i]=b[i]/a[i]*1.0;
	}
	sort(c,c+m);
	cout<<fixed<<setprecision(8)<<n/c[m-1]<<endl;
}