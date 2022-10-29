#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str,mok;
	cin>>str>>mok;
	int mini=1000000000;
	for(int i=-int(mok.size());i<int(str.size());i++)
	{
		int sum=0;
		for(int j=0;j<mok.size();j++)
		{
			if(i+j<0||i+j>=int(str.size()))
			{
				sum++;
			}
			else
			{
				if(str[i+j]!=mok[j])
				{
					sum++;
				}
			}
		}
		mini=min(mini,sum);
	}
	printf("%d\n",mini);
}