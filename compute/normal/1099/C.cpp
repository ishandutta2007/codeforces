#include<iostream>
#include<vector>
using namespace std;
vector<int> snow,candy;
int main()
{
	string s;
	int k;
	cin>>s;
	cin>>k;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='?') candy.push_back(i-1);
		else if(s[i]=='*') snow.push_back(i-1);
	}
	int reallen=s.length()-snow.size()-candy.size();
	if((!snow.size()&&reallen<k)||(reallen-candy.size()-snow.size()>k))
	{
		cout<<"Impossible"<<endl;
	}
	else{
		if(reallen<k)
		{
			int need=k-(reallen-candy.size());
			for(int i=0;i<s.size();i++)
			{
				bool skip=0;
				for(int j=0;j<candy.size();j++)
					if(candy[j]==i) skip=1;
				if(s[i]=='?'||s[i]=='*'||skip) continue;
				if(i==snow[0])
				{
					for(int j=0;j<need;j++)
						cout<<s[i];
				}
				cout<<s[i];
			}
		}
		else{
			int need=reallen-k;
			int cnt=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='*'||s[i]=='?') continue;
				bool skip=0;
				for(int j=0;j<candy.size();j++)
					if(candy[j]==i) skip=1;
				for(int j=0;j<snow.size();j++)
					if(snow[j]==i) skip=1;
				if(skip&&cnt<need)
				{
					cnt++;continue;
				}
				cout<<s[i];
			}
		}
		cout<<endl;
	}
}