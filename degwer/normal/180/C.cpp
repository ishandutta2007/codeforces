#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int han(char a)
{
	if(a>='a'&&a<='z')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	string str;
	cin>>str;
	vector<int>vec;
	int now=0;
	for(int i=0;i<str.size();i++)
	{
		vec.push_back(now);
		if(han(str[i])==0)
		{
			now++;
		}
	}
	vec.push_back(now);
	reverse(str.begin(),str.end());
	int now2=0;
	int mini=10000000;
	for(int j=0;j<str.size();j++)
	{
		mini=min(mini,now2+vec[str.size()-j]);
		if(han(str[j])==1)
		{
			now2++;
		}
	}
	mini=min(mini,now2+vec[0]);
	printf("%d\n",mini);
}