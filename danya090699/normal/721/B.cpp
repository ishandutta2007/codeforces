#include <iostream>
#include <fstream>
using namespace std;
main()
{
	int n, k, samel=0, sma=0, same=0;
	cin>>n>>k;
	string s[n], pa;
	for(int a=0; a<n; a++) cin>>s[a];
	cin>>pa;
	for(int a=0; a<n; a++)
	{
		if(s[a]==pa) same++;
		if(s[a].size()<pa.size()) sma++;
		if(s[a].size()==pa.size()) samel++;
	}
	samel-=same;
	cout<<sma+(sma/k)*5+1<<" "<<sma+samel+((sma+samel)/k)*5+1;
}