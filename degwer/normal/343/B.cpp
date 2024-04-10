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
	vector<char>vec;
	for(int i=0;i<str.size();i++)
	{
		vec.push_back(str[i]);
		if(vec.size()>=2)
		{
			if(vec[vec.size()-1]==vec[vec.size()-2])
			{
				vec.pop_back();
				vec.pop_back();
			}
		}
	}
	if(vec.empty())
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}