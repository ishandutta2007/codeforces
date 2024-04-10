#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int toint(char a)
{
	int ret=a-'0';
	return ret;
}

int main()
{
	string str,str2;
	cin>>str;
	cin>>str2;
	vector<int>vec;
	int hai[10];
	fill(hai,hai+10,0);
	for(int i=1;i<=str.size();i++)
	{
		vec.push_back(toint(str[i-1]));
	}
	for(int k=1;k<=str2.size();k++)
	{
		hai[toint(str2[k-1])]++;
	}
	int dai=9;
	for(int j=1;j<=vec.size();j++)
	{
		for(;;)
		{
			if(hai[dai]==0)
			{
				dai--;
			}
			else
			{
				break;
			}
		}
		if(dai>vec[j-1])
		{
			vec[j-1]=dai;
			hai[dai]--;
		}
	}
	for(int l=1;l<=vec.size();l++)
	{
		printf("%d",vec[l-1]);
	}
	printf("\n");
}