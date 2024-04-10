#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
string st,ans;
int i,j;
int main()
{
	//freopen("ouput.txt","w",stdout);
	getline(cin,st);
	for (i=0;i<st.length();i++)
	{
		if (st[i]==',')
		{
			ans+=", ";
		}
		else if (st[i]=='.')
		{
			i+=2;
			ans+=" ...";
		}
		else if (st[i]==' ') 
		{
			continue;
		}
		else
		{
			//if (!i||st[i-1]>'9'||st[i-1]<'0') ans.push_back(' ');
			while (i<st.length()&&st[i]!=','&&st[i]!='.'&&st[i]!=' ') 
			{
			    ans.push_back(st[i]);
			    i++;
			}
			while (st[i]==' ') i++;
			if (st[i]!=','&&st[i]!='.'&&st[i]!=' ') ans.push_back(' ');
			if (i<st.length()) i--; 
		}
	}
	//cerr<<ans<<endl;
	for (i=0;i<ans.length();i++)
	{
		if (ans[i]==' '&&(!i||i+1==ans.length()||ans[i+1]==' ')) continue;
		cout<<ans[i];
	}
	return 0;
}