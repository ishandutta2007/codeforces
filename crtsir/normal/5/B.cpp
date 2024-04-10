#include<bits/stdc++.h>
using namespace std;
string ts[1003];
bool where;
int main()
{
	int n=-1,w=-1;
	while(1)
	{
		if(!getline(cin,ts[++n]))break;
		int x=ts[n].size();
		w=max(x,w); 
	}
	for(int i=0;i<w+2;i++)
		cout<<'*';
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		int x=w-ts[i].size();
		if(x%2)
		{
			x+=where;
			where=!where;
			x/=2;
		}
		else
			x/=2;
		cout<<"*"<<(string(x,' '))+ts[i]+string(w-ts[i].size()-x,' ')<<"*\n";
	}
	for(int i=0;i<w+2;i++)
		cout<<'*';
}