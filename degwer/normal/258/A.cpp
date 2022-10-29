#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	vector<char>ans;
	bool han=false;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0')
		{
			if(!han)
			{
				han=true;
			}
			else
			{
				ans.push_back(str[i]);
			}
		}
		else
		{
			ans.push_back(str[i]);
		}
	}
	if(!han)
	{
		ans.pop_back();
	}
	if(ans.size()==0)
	{
		ans.push_back('0');
	}
	for(int i=0;i<ans.size();i++)
	{
		printf("%c",ans[i]);
	}
	printf("\n");
}