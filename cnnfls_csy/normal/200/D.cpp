#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,k,i,j,cnt,pos;
map<string,vector<vector<int>/**/>/**/> all;
map<string,int> mp,typ;
string st,st1,name;
vector<int> in;
int main()
{
	//ios::sync_with_stdio(0);
	cin>>n;
	getline(cin,st);
	mp["T"]=0;
	for (i=1;i<=n;i++)
	{
		getline(cin,st);
		pos=st.find('d');
		st=st.substr(pos+1);
		int l=st.length();
		st1="";
		for (j=0;j<l;j++)
		{
			if (st[j]!=' ') st1.push_back(st[j]);
		}
		st=st1;
		l=st.length();
		pos=st.find('(');
		name=st.substr(0,pos);
		//cerr<<name<<endl;
		st=st.substr(pos+1);
		in.clear();
		while ((pos=((int)st.find(',')))!=-1)
		{
			st1=st.substr(0,pos);
			st=st.substr(pos+1);
			if (!mp.count(st1)) mp[st1]=++cnt;
			in.push_back(mp[st1]);
		}
		while ((pos=((int)st.find(')')))!=-1)
		{
			st1=st.substr(0,pos);
			st=st.substr(pos+1);
			if (!mp.count(st1)) mp[st1]=++cnt;
			in.push_back(mp[st1]);
		}
		all[name].push_back(in);
	}
/*	for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		cerr<<it->first<<' '<<it->second<<endl;
	}*/
//	for (map<string,vector<vector<int>/**/>/**/>::iterator it=all.begin();it!=all.end();it++)
/*	{
		cerr<<it->first<<endl;
		for (i=0;i<(it->second).size();i++)
		{
			for (j=0;j<(it->second)[i].size();j++)
			{
				cerr<<(it->second)[i][j]<<' ';
			}
			cerr<<endl;
		}
		cerr<<endl;
	}*/
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>st>>name;
		typ[name]=mp[st];
	}
/*	for (map<string,int>::iterator it=typ.begin();it!=typ.end();it++)
	{
		cerr<<it->first<<' '<<it->second<<endl;
	}*/
	cin>>k;getline(cin,st);
	for (i=1;i<=k;i++)
	{
		getline(cin,st);
		int l=st.length();
		st1="";
		for (j=0;j<l;j++)
		{
			if (st[j]!=' ') st1.push_back(st[j]);
		}
		st=st1;
		l=st.length();
		pos=st.find('(');
		name=st.substr(0,pos);
		st=st.substr(pos+1);
		in.clear();
		while ((pos=((int)st.find(',')))!=-1)
		{
			st1=st.substr(0,pos);
			st=st.substr(pos+1);
			if (!typ.count(st1)) typ[st1]=-1;
			in.push_back(typ[st1]);
		}
		while ((pos=((int)st.find(')')))!=-1)
		{
			st1=st.substr(0,pos);
			st=st.substr(pos+1);
			if (!typ.count(st1)) typ[st1]=-1;
			in.push_back(typ[st1]);
		}
		vector<vector<int>/**/> now=all[name];
		int cnt=0;
		for (vector<vector<int>/**/>::iterator it=now.begin();it!=now.end();it++)
		{
			if ((*it).size()!=in.size()) continue;
			cnt++;
			for (j=0;j<in.size();j++)
			{
				if (in[j]==-1)
				{
					cnt--;
					break;
				}
				if ((*it)[j]==0)
				{
					continue;
				}
				if ((*it)[j]!=in[j])
				{
					cnt--;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}