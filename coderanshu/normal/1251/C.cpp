#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

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
	long int i,j,temp,n,t;
	string s1,s2,s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		s1.clear();s2.clear();
		n=s.length();
		for(i=0;i<n;i++)
		{
			if(s[i]%2)
				s2+=s[i];
			else
				s1+=s[i];
		}
		s.clear();
		i=0;j=0;
		while(i<s1.length() && j<s2.length())
		{
			if(s1[i]<s2[j])
			{
				s+=s1[i];i++;
			}
			else
			{
				s+=s2[j];j++;
			}
		}
		for(temp=i;temp<s1.length();temp++)
			s+=s1[temp];
		for(temp=j;temp<s2.length();temp++)
			s+=s2[temp];
		cout<<s<<"\n";
	}
	return 0;
}