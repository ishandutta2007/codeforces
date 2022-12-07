#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	string s;
	cin>>s;
	int n=s.size(), su=0, yk=0;
	while(yk<n)
	{
		if((s[yk]>=97)and(s[yk]<=122)) yk++;
		else
		{
			int cu=0, st=yk;
			while(yk<n)
			{
				if((s[yk]>=97)and(s[yk]<=122)) break;
				else
				{
					if(s[yk]!='.') cu=cu*10+s[yk]-48;
					yk++;
				}
			}
			if(yk-3>=st)
			{
				if(s[yk-3]=='.') su+=cu;
				else su+=cu*100;
			}
			else su+=cu*100;
		}
	}
	int ost=su%100;
	su/=100;
	vector <int> an;
	while(1==1)
	{
		an.push_back(su%10);
		su/=10;
		if(su==0) break;
	}
	for(int a=an.size()-1; a>=0; a--)
	{
		cout<<an[a];
		if((a%3==0)and(a!=0)) cout<<".";
	}
	if(ost!=0)
	{
		cout<<".";
		if(ost<10) cout<<"0";
		cout<<ost;
	}
}