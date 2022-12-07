#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, t;
	cin>>n>>t;
	int an[n], poi=0;
	an[0]=0;
	for(int a=0; a<n; a++)
	{
		char sy;
		cin>>sy;
		if(sy=='.') poi=a+1;
		else
		{
			int z=sy-48;
			if(poi==0) an[a+1]=z;
			else an[a]=z;
		}
	}
	int yk;
	for(yk=poi; yk<n; yk++)
	{
		if(an[yk]>4) break;
	}
	if(yk!=n)
	{
		while((t!=0)and(yk>=poi))
		{
			if(an[yk]>4)
			{
				yk--, t--;
				while(an[yk]==9)
				{
					an[yk]=0, yk--;
				}
				an[yk]++;
			}
			else break;
		}
	}
	else yk--;
	if(an[0]!=0) cout<<an[0];
	for(int a=1; a<poi; a++) cout<<an[a];
	if(yk>=poi)
	{
		cout<<".";
		for(int a=poi; a<=yk; a++) cout<<an[a];
	}
}