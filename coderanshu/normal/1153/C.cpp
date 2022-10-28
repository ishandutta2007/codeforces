#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;int n,open,close,i,count;
	cin>>n>>s;
	if(s[0]=='?')s[0]='(';
	if(s[n-1]=='?')s[n-1]=')';
	if(s[0]!='(' || s[n-1]!=')' || n%2)
	{
		cout<<":(";return 0;
	}
	open=close=n/2;
	for(i=0;s[i];i++)
	{
		if(s[i]=='(')--open;
		else if(s[i]==')')--close;
	}
	count=0;
	// both open and close remaining must be zero for a regular bracket sequence...
	if(open<0 || close<0)
	{
		cout<<":(";return 0;
	}
	for(i=0;i<n-1;i++)
	{
		if(s[i]=='?')
		{
			if(open>0){s[i]='(';--open;}
			else if(close>0){s[i]=')';--close;}
		}
		count+=(s[i]=='(')?1:-1;
		if(count<=0)
		break;
	}
	if(count<=0)cout<<":(";
	else cout<<s;
	return 0;
}