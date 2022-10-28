#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,n,found,ans,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ans=0;found=1;
		ans+=(s.length()-1)*9;
		for(i=1;i<s.length();i++)
		{
			if(s[i]>s[0])
			{
				break;
			}
			else if(s[i]<s[0])
			{
				found=0;break;
			}
		}
		ans+=s[0]-48;
		if(!found)
		{
			ans--;
		}
		cout<<ans<<"\n";
		s.clear();
	}
	return 0;
}