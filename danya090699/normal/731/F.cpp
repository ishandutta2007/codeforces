#include <iostream>
#include <fstream>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	int n, ma=400000, ans=0;
	cin>>n;
	int ar[n], ar2[ma+1], su[ma/2+1];
	for(int a=0; a<=ma; a++) ar2[a]=0;
	for(int a=0; a<n; a++)
	{
		cin>>ar[a];
		ar2[ar[a]]++;
	}
	for(int a=1; a<=ma; a++) ar2[a]+=ar2[a-1];
	for(int a=1; a<=ma/2; a++)
	{
		int csu=0;
		for(int b=1; a*b<=ma/2; b++)
		{
			csu+=(ar2[a*(b+1)-1]-ar2[a*b-1])*b*a;
		}
		su[a]=csu;
	}
	for(int a=0; a<n; a++) ans=max(ans, su[ar[a]]);
	cout<<ans;
}