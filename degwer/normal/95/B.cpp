#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
vector<int>tov(string a)
{
	vector<int>ret;
	for(int i=0;i<a.size();i++)
	{
		ret.push_back(a[i]-'0');
	}
	return ret;
}
int main()
{
	string str;
	cin>>str;
	vector<int>vec=tov(str);
	vector<int>zan;
	for(int i=0;i<vec.size();i++)
	{
		zan.push_back(7);
	}
	if(vec>zan)
	{
		vec.push_back(4);
		for(int i=0;i<vec.size();i++)
		{
			vec[i]=4;
		}
	}
	if(vec.size()%2==1)
	{
		vec.push_back(4);
		for(int i=0;i<vec.size();i++)
		{
			vec[i]=4;
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]<4)
		{
			for(int j=i;j<vec.size();j++)
			{
				vec[j]=4;
			}
			break;
		}
		else
		{
			if(vec[i]<7)
			{
				if(vec[i]>4)
				{
					vec[i]=7;
					for(int j=i+1;j<vec.size();j++)
					{
						vec[j]=4;
					}
					break;
				}
			}
			else
			{
				if(vec[i]>7)
				{
					for(int j=i;j<vec.size();j++)
					{
						vec[j]=4;
					}
					for(int j=i-1;j>=0;j--)
					{
						if(vec[j]==7)
						{
							vec[j]=4;
						}
						else
						{
							vec[j]=7;
							break;
						}
					}
				}
			}
		}
	}
	int num4=0,num7=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]==4)
		{
			num4++;
		}
		else
		{
			num7++;
		}
	}
	reverse(vec.begin(),vec.end());
	if(num4<num7)
	{
		for(int i=0;i<vec.size();i++)
		{
			if(num4>=num7)
			{
				break;
			}
			if(vec[i]==7)
			{
				for(int j=i;;j++)
				{
					if(j==vec.size())
					{
						vec.push_back(4);
						vec.push_back(4);
						for(int k=0;k<vec.size()/2;k++)
						{
							vec[k]=7;
						}
						for(int k=vec.size()/2;k<vec.size();k++)
						{
							vec[k]=4;
						}
						num4=num7=vec.size()/2;
						break;
					}
					if(vec[j]==4)
					{
						num4--;
						num7++;
						vec[j]=7;
						break;
					}
					vec[j]=4;
					num4++;
					num7--;
				}
			}
		}
	}
	if(num4>num7)
	{
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]==4)
			{
				vec[i]=7;
				num4--;
				num7++;
				if(num4==num7)
				{
					break;
				}
			}
		}
	}
	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		printf("%d",vec[i]);
	}
	printf("\n");
}