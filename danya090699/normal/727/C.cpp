#include <iostream>
using namespace std;
main()
{
	int n, s12, s13, s23;
	cin>>n;
	int ar[n];
	cout<<"? "<<1<<" "<<2<<"\n";
	cin>>s12;
	cout<<"? "<<1<<" "<<3<<"\n";
	cin>>s13;
	cout<<"? "<<2<<" "<<3<<"\n";
	cin>>s23;
	ar[1]=(s23-(s13-s12))/2;
	ar[0]=s12-ar[1];
	ar[2]=s13-ar[0];
	for(int a=3; a<n; a++)
	{
		int csu;
		cout<<"? "<<1<<" "<<a+1<<"\n";
		cin>>csu;
		ar[a]=csu-ar[0];
	}
	cout<<"!";
	for(int a=0; a<n; a++) cout<<" "<<ar[a];
}