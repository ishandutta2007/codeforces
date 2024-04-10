#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define pi 3.1415926536

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	ll t,i,j;
	int f1[26],f2[26];
	bool found,ans;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		mem0(f1);
		if(s1.length()>s2.length())
		{
			cout<<"NO\n";
			continue;
		}
		found=false;
		for(i=0;s1[i];i++)
			f1[s1[i]-'a']++;
		for(i=0;i<=s2.length()-s1.length();i++)
		{
			mem0(f2);ans=true;
			for(j=0;j<s1.length();j++)
			{
				f2[s2[j+i]-'a']++;
			}
			for(j=0;j<26;j++)
			{
				if(f1[j]!=f2[j])
				{
					ans=false;
					break;
				}
			}
			if(ans)
			{
				found=true;
				break;
			}
		}
		if(found)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}