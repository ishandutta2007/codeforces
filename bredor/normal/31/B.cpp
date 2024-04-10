//  228

/*====================================
Auther:    Shyam Makwana
Problem:   31B.cpp
====================================*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define add(a,b) ((a%mod)+(b%mod))%mod
#define mul(a,b) ((a%mod)*(b%mod))%mod
#define __lcm(a,b) ((a*b)/__gcd(a,b))
#define endl "\n"
#define MAX 100005

int32_t main()
{
	int n,m,a,b,c,d,n1;	
	int max1=INT_MIN,min1=INT_MAX;
	bool flag=true,flag1=true;
	fastio;	
	string str;

	cin>>str;
	int cnt=0;
	string s="";
	string ans="";

	flag1=false;
	for(int i=0;i<str.length();i++)
	{
		if(cnt==0 && str[i]=='@')
		{
			flag=false;
			break;
		}
		if(str[i]=='@')
		{
			s+='@';
			flag1=true;
			cnt=0;
		}
		else if(flag1 && str[i]!='@')
		{
			flag1=false;
			s+=str[i];
			s+=',';			
			ans+=s;
			s="";			
			cnt=0;
		}
		else if(str[i]!='@')
		{
			s+=str[i];
			cnt++;			
		}
	}	
	// cout<<ans<<endl;
	if(!flag)
		cout<<"No solution"<<endl;		
	else
	{
		if(ans=="")
			cout<<"No solution"<<endl;
		else if(cnt!=0 && flag1==false)
		{
			ans.pop_back();
			ans+=s;
			cout<<ans<<endl;
		}
		else if(flag1)
			cout<<"No solution"<<endl;		
		else
		{
			if(ans[ans.length()-1]==',')
				ans.pop_back();
			cout<<ans<<endl;
		}		
	}
}