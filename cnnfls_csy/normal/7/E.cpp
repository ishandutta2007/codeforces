#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#include<sstream> 
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,pos;
string st1;
map<string,string> d;
map<string,char> f;
string st;
bool good=1;
char expr(string &st,int &pos);
char parse(string st1);
char fact(string &st,int &pos)
{
	if(st[pos]=='(')
	{
		pos++;
		char v = expr(st, pos);
		pos++;
		return ' ';
	}
	string st1="";
	while (isalnum(st[pos]))
	{
		st1.push_back(st[pos]);
		pos++;
	}
	if (d.count(st1)) return parse(d[st1]);
	return ' ';
}
char term(string &st,int &pos)
{
	char r = fact(st,pos);
	while(st[pos]=='*' || st[pos]=='/')
	{
		char op = st[pos];
		pos++;
		string s1 = "";
		int p1 = pos - 2;
		while(p1>=0 && isalpha(st[p1])) s1.push_back(st[p1]),p1--;
		reverse(s1.begin(),s1.end());
		string s2 = "";
		int p2 = pos;
		while(isalpha(st[p2])) s2.push_back(st[p2]),p2++;
		if (d.count(s1)&&d.count(s2))
		{
			char v1=parse(d[s1]);
			char v2=parse(d[s2]);	
			if (op=='*'&&(v1=='+'||v2=='+')) good=0;
			if (op=='/'&&(v1=='+'||v2!=' ')) good=0;
		}
		else if(d.count(s1))
		{
			char v1=parse(d[s1]);
			if (op=='*'&&v1=='+') good=0;
			if (op=='/'&&v1=='+') good=0;
		}
		else if(d.count(s2))
		{
			char v2=parse(d[s2]);
			if (op=='*'&&v2=='+') good=0;
			if (op=='/'&&v2!=' ') good=0;
		}
		char v=fact(st,pos);
		r='*';
	}
	return r;
}
char expr(string &st,int &pos)
{
	char r=term(st,pos);
	while (st[pos]=='+'||st[pos]=='-')
	{
		char op=st[pos];
		pos++;
		string s2="";
		int p2=pos;
		while (isalpha(st[p2]))
		{
			s2.push_back(st[p2]);
			p2++;
		}
		if (d.count(s2))
		{
			char v2=parse(d[s2]);
			if(op=='-' && v2=='+') good=0;
		}
		char v=term(st,pos);
		r='+';
	}
	return r;
}
char parse(string st1)
{
	if(f.count(st1)) return f[st1];
	int pos=0;
	return f[st1]=expr(st1,pos);
}
int main()
{
	cin>>n;
	getline(cin,st1);
	for (i=1;i<=n;i++)
	{
		getline(cin,st1);
		pos=0;
		while(st1[pos]!='#') pos++;
		while(st1[pos]!='e') pos++;
		pos++;
		while(st1[pos]!='e') pos++;
		pos++;
		while(st1[pos]==' ') pos++;
		string name="";
		while(st1[pos]!=' ') name.push_back(st1[pos]),pos++;
		string val= "";
		for (j=pos;j<st1.size();j++)
		{
			if (st1[j]!=' ')
			{
				val.push_back(st1[j]);
			}
		}
		d[name]=val;
	}
	getline(cin,st1);
	string t="";
	for (i=0;i<st1.length();i++)
	{
		if (st1[i]!=' ') t.push_back(st1[i]);
	}
	pos=0;
	expr(t,pos);
	if (!good) puts("Suspicious");
		else puts("OK");
	return 0;
}