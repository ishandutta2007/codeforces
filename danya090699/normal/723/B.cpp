#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n;
	string s;
	cin>>n>>s;
	int lon=0, q=0, ins=0, a=0;
	while(a<n)
	{
		if(s[a]=='(')
		{
			ins=1, a++;
		}
		else if(s[a]==')')
		{
			ins=0, a++;
		}
		else if(s[a]!='_')
		{
			int le=0;
			while(a<n)
			{
				if((s[a]!='_')and(s[a]!='(')and(s[a]!=')'))
				{
					le++, a++;
				}
				else break;
			}
			if(ins) q++;
			else lon=max(lon, le);
		}
		else a++;
	}
	cout<<lon<<" "<<q;
}