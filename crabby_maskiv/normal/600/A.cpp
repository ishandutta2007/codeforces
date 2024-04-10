#include<iostream>
#include<cstring>
using namespace std;
string a,b;
string s;
bool f(const string &str)
{
	int len=str.length();
	if(len==0) return 0;
	if(str[0]=='0'&&len>1) return 0;
	for(int i=0;i<len;i++) 
	    if(str[i]<'0'||str[i]>'9') return 0;
	return 1;
}
void print(string s)
{
	int len=s.length();
	cout<<'"';
	for(int i=0;i<len-1;i++) cout<<s[i];
	cout<<'"'<<endl;
}
int main()
{
	cin>>s;
	s+=",";
	int i,j=0;
	int len=s.length();
	for(i=0;i<len;i++)
	{
		if(s[i]==';'||s[i]==',')
		{
		    string tmp=s.substr(j,i-j);
			if(f(tmp)==1) a+=(tmp+',');
			else b+=(tmp+',');
			j=i+1;
		}
	}
	a[a.length()-1]='\0';
	b[b.length()-1]='\0';
	if(a=="") cout<<'-'<<endl;
	else print(a);
	if(b=="") cout<<'-'<<endl;
	else print(b);
	return 0;
}