#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main()
{
	ifstream in("input.txt");
	string s;
	cin>>s;
	int n=s.size();
	char le[4]={'R', 'B', 'Y', 'G'};
	int ar[4]={-1, -1, -1, -1};
	for(int a=0; a<n; a++)
	{
		if(s[a]!='!')
		{
			int nu;
			for(int b=0; b<4; b++) if(le[b]==s[a]) nu=b;
			ar[nu]=a%4;
		}
	}
	for(int a=0; a<4; a++)
	{
		if(ar[a]==-1)
		{
			for(int b=0; b<4; b++)
			{
				int pos=1;
				for(int c=0; c<4; c++) if(ar[c]==b) pos=0;
				if(pos)
				{
					ar[a]=b;
					break;
				}
			}
		}
		int an=0;
		for(int b=ar[a]; b<n; b+=4) if(s[b]=='!') an++;
		cout<<an<<" ";
	}
}