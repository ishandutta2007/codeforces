#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
vector<string>str;
bool fd(string s)
{
	for(int i=0;i<str.size();i++)
		if(s==str[i])
			return true;
	return false;
}
int eval(string s)
{
	string t;
	int ind1=0;
	int c1=0,c2=0;
	while(!isalpha(s[ind1])&&ind1<s.size())++ind1,++c1;
	int ind2=s.size()-1;
	while(s[ind2]=='*'&&ind2>-1)--ind2,++c2;
	t=s.substr(ind1,ind2-ind1+1);
	int x=mp[t];
	if(x==-1)
		return -1;
	x=x-c1+c2;
	if(x<0)
		return -1;
	return x;
}
int main()
{
	int n;
	cin>>n;
	mp["void"]=0;
	str.push_back("void");
	for(int i=0;i<n;i++)
	{
		string ws;
		cin>>ws;
		if(ws=="typeof")
		{
			string s;
			cin>>s;
			int x=eval(s);
			string t="";
			for(int j=0;j<s.size();j++)
				if(isalpha(s[j]))
					t=t+s[j];
			s=t;
			if(x==-1)
				cout<<"errtype"<<endl;
			else if(!fd(s))
			{
				cout<<"errtype"<<endl;
				str.push_back(s);
				mp[s]=-1;
				continue;
			}
			else
			{
				cout<<"void";
				for(int j=0;j<x;j++)
					cout<<"*";
				cout<<endl;
			}
		}else{
			string s,t;
			cin>>s>>t;
			int js=0;
			string tmp="";
			mp[t]=eval(s)+js;
			for(int j=0;j<s.size();j++)
				if(isalpha(s[j]))
					tmp=tmp+s[j];
			s=tmp;
			if(!fd(s))
			{
				str.push_back(s);
				str.push_back(t);
				mp[t]=-1;
				mp[s]=-1;
				continue;
			}
			str.push_back(t);
		}
	}
}