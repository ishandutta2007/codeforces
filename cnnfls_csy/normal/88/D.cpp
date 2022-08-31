#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
map<string,int> a;
string st,st1,st2,st3;
int n,i,j,x;
int main()
{
	a["void"]=0;
	cin>>n;
	for (int h=1;h<=n;h++)
	{
		cin>>st;
		if (st=="typedef")
		{
			cin>>st1>>st2;
			st3="";
			x=0;
			for (i=0;i<st1.length()&&st1[i]=='&';i++) x--;
			for (j=st1.length()-1;j>=0&&st1[j]=='*';j--) x++;
			st3=st1.substr(i,j-i+1);
			//cout<<st3<<' '<<x<<endl;
			if (a.find(st3)==a.end()||a[st3]+x<0) a[st2]=-2147480000;
			else a[st2]=a[st3]+x;
		}
		else
		{
			cin>>st1;
			st3="";
			x=0;
			for (i=0;i<st1.length()&&st1[i]=='&';i++) x--;
			for (j=st1.length()-1;j>=0&&st1[j]=='*';j--) x++;
			st3=st1.substr(i,j-i+1);
			//cout<<st3<<' '<<x<<endl;
			if (a.find(st3)==a.end()||a[st3]+x<0)cout<<"errtype"<<endl;
			else 
			{
				cout<<"void";
				for (i=1;i<=a[st3]+x;i++)
				cout<<'*';
				cout<<endl;
			}
		}
	}
	return 0;
}