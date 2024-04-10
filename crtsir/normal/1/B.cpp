#include<bits/stdc++.h>
using namespace std;
string toStr(int x)
{
	string s="";
	while(x)
	{
		s=char('0'+(x%10))+s;
		x/=10;
	}
	return s;
}
int toNum(string s)
{
	int x=0;
	for(int i=0;i<s.size();i++)
		x=10*x+s[i]-'0';
	return x;
}
int getId(string s)
{
	int res=1;
	int z=1;
	for(int i=s.size()-1;i>-1;i--){
		res+=(s[i]-'A')*z;
		z*=26;
		if(i)
			res+=z;
	}
	return res;
}
string getStr(int id)
{
	id--;
	int len=1;
	int z=26;
	while(id>=z)
	{
		id-=z;
		z*=26;
		len++;
	}
	string s="";
	for(int i=0;i<len;i++)
		s+='A';
	for(int i=0;i<len;i++)
	{
		z/=26;
		while(id>=z)
		{
			id-=z;
			s[i]++;
		}
	}
	return s;
}
bool checktype(string s)
{
	for(int i=1;i<s.size()-1;i++)
		if(isalpha(s[i])&&isdigit(s[i-1])&&isdigit(s[i+1]))
			return false;
	return true;
}
string solve1(string s)
{
	int id=0;
	while('A'<=s[id]&&s[id]<='Z')id++;
	return "R"+s.substr(id,s.size()-id)+"C"+toStr(getId(s.substr(0,id)));
}
string solve2(string s)
{
	int id=1;
	while('0'<=s[id]&&s[id]<='9')id++;
	return getStr(toNum(s.substr(id+1,s.size()-id-1)))+s.substr(1,id-1);
}
string solve()
{
	string s;
	cin>>s;
	if(checktype(s))return solve1(s);
	else return solve2(s);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<solve()<<endl;
}