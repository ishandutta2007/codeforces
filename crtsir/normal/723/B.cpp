#include<bits/stdc++.h>
using namespace std;
string xs[512];
bool ifin[512];
int js=-1;
int main()
{
	string s;
	cin>>s;
	cin>>s;
	s='_'+s+'_';
	bool in=false;
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		    xs[js].push_back(s[i]),
		    ifin[js]=in;
		else
		{
			while(!isalpha(s[i]))
			{
				if(s[i]=='(')
				    in=true;
				if(s[i]==')')
				    in=false;
				i++;
		    }
		    i--;
			js++;
		}
	}
	int cnt=0,si=0;
	for(int i=0;i<js;i++)
	{
	    if(ifin[i])
	        cnt++;
	    else
	        si=max(int(xs[i].size()),si);
	}
	cout<<si<<' '<<cnt;
}