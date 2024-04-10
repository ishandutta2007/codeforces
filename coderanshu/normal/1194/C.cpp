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
#define PI 3.1415926536
#define INF 

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
int freq[26];
bool check(string p)
{
	int freq2[26];
	mem0(freq2);
	for(auto i=0;p[i];i++)
	{
		freq2[p[i]-'a']++;
	}
	for(auto i=0;i<26;i++)
	{
		if(freq[i]>freq2[i])
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,q;
	cin>>q;
	string s,t,p;
	while(q--)
	{
		cin>>s>>t>>p;
		j=0;
		mem0(freq);
		for(i=0;t[i];i++)
		{
			if(t[i]==s[j] && j<s.length())
			{
				j++;
			}
			else
			{
				freq[t[i]-'a']++;
			}
		}
			if(j!=s.length())
			{
				cout<<"NO\n";
			}
			else
			{
				if(check(p))
				{
					cout<<"YES\n";
				}
				else cout<<"NO\n";
			}
		
	}
	return 0;
}