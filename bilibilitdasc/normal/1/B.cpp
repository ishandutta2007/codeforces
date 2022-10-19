#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string intstr(int i)
{
	string s="";
	while(i)
	{
		s=(char)(i%10+'0')+s;
		i/=10;
	}
	return s;
}
int strint(string str)
{
	int num=0;
	for(int i=0;i<str.size();++i)
	num=num*10+str[i]-'0';
	return num;
}
int getint(string s)
{
	int ans=1,pw=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=(s[i]-'A')*pw;
		pw*=26;
		if(i)
		ans+=pw;
	}
	return ans;
}
string getstr(int i)
{
	i--;
	string s="";
	int l=1,z=26;
	while(i>z)
	{
		i=i-z;
		z*=26;
		l++;
	}
	for(int f=0;f<l;f++)
	s+='A';
	for(int f=0;f<l;f++)
	{
		z/=26;
		while(i>=z)
		{
			i-=z;
			s[f]++;
		}
	}
	return s;
}
bool iftp(string s)
{
	int num=0;
	while(!isdigit(s[num]))
	num++;
	for(;num<s.size();num++)
	if(!isdigit(s[num]))
	return 0;
	return 1; 
}
string sv1(string s)
{
	int i=0;
	for(;!isdigit(s[i]);i++);
	return "R"+s.substr(i)+'C'+intstr(getint(s.substr(0,i)));
} 
string sv2(string s)
{
	int i=1;
	for(;isdigit(s[i]);i++);
	return getstr(strint(s.substr(i+1)))+s.substr(1,i-1);
}
void solve()
{
	string s;
	cin>>s;
	if(iftp(s))
	cout<<sv1(s)<<'\n';
	else
	cout<<sv2(s)<<'\n';
}
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}