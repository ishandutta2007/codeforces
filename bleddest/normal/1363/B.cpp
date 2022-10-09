#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define t_case ll t;cin>>t;while(t--)
#define left(nod) 2*nod
#define right(nod) 2*nod+1
#define ss second
#define ff first
#define pb push_back
 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		ll f1[1009],b1[1009];
		
		f1[0]=s[0]-'0';
		for(ll i=1;i<s.length();i++)
		f1[i]=f1[i-1]+s[i]-'0';
		
		b1[s.length()-1]=s[s.length()-1]-'0';
		for(ll i=s.length()-2;i>=0;i--)
		b1[i]=b1[i+1]+s[i]-'0';
		
		ll mini=INT_MAX;b1[s.length()]=0;ll n=s.length();
		for(ll i=0;i<s.length();i++)
		{
			ll c1=f1[i]+(n-i-1-b1[i+1]);
			ll c2=i+1-f1[i]+b1[i+1];
			
			mini=min(mini,min(c1,c2));
		}
		cout<<min(mini,n-f1[n-1])<<endl;
	}
			
		
}