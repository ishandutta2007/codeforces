#include<bits/stdc++.h>
using namespace std;
set<string>s;
string tmp;
int ans=0;
int main()
{
	ans=0;
	s.clear();
	while(getline(cin,tmp))
	{
		if(tmp[0]=='+')
		{
			tmp[0]=' ';
			s.insert(tmp);
		}
	
	
		else if(tmp[0]=='-')
		{
			tmp[0]=' ';
			s.erase(tmp);
		}
		else 
		{
		    int l;
			for( l=0;l<tmp.size();l++)
			{
				if(tmp[l]==':')break;
				
			}
			ans += (tmp.size()-l-1) *s.size();
		}
	}
	cout<<ans<<endl;
	return 0;
}