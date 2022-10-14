#include<bits/stdc++.h>
using namespace std;
int qwq(int a,int b) { if(a>b) return b; else return a;}
int main()
{
	int n,b,f,kkk;
	cin>>n;
	string str;
	for(int i=1; i<=n; i++)
	{
		cin>>kkk;
		cin>>str;
		b=str.size()-1;
		f=0;
		for(int i=0; i<str.size(); i++) 
		{
			if(str[i]=='>')  
			{
				f=i;
				break;
			}
		}
		for(int i=str.size()-1; i>=0; i--) 
		{
			if(str[i]=='<')  
			{
				b=i;
				break;
			}
		}
		cout<<qwq(f,str.size()-1-b)<<endl;
	}
	return 0;
}