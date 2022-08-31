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
int n,i;
string st,now;
vector<pair<string,bool>/**/> word;
int main()
{
	getline(cin,st);
	i=0;
	while (i<st.length())
	{
		while (i<st.length()&&st[i]==' ') i++;
		if (i>=st.length()) break;
		now="";
		if (st[i]>'z'||st[i]<'a') 
		{
			now.push_back(st[i]);
			i++;
			word.push_back(make_pair(now,0));
		}
		else 
		{
			while (st[i]>='a'&&st[i]<='z')
			{
				now.push_back(st[i]);
				i++;	
			}
			word.push_back(make_pair(now,1));
		}
	}
	for (i=0;i<word.size();i++)
	{
		cout<<word[i].first;
		if (word.size()-1>i&&word[i+1].second) cout<<' ';
	}
	return 0;
}