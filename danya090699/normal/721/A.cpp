#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
main()
{
	int n, qu=0;
	string s;
	cin>>n>>s;
	int a=0;
	vector <int> ve;
	while(a<n)
	{
		if(s[a]=='W') a++;
		else
		{
			int q=0;
			while(a<n)
			{
				if(s[a]=='B')
				{
					a++, q++;
				}
				else break;
			}
			ve.push_back(q);
			qu++;
		}
	}
	cout<<qu<<"\n";
	for(int a=0; a<ve.size(); a++) cout<<ve[a]<<" ";
}