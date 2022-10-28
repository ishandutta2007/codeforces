#pragma GCC optimize("Ofast")

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
#define INF 2e9
#define endl "\n"
string s;
bool check(int a,int  b,int c)
{
	return (100*a+10*b+c)%8==0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,k;
	cin>>s;
	int n=s.length();
	for(i=0;i<n;i++)
	{
		if(check(0,0,s[i]-'0'))
		{
			cout<<"YES\n";
			cout<<s[i];return 0;
		}
		for(j=i+1;j<n;j++)
		{
			if(check(0,s[i]-'0',s[j]-'0'))
			{
				cout<<"YES\n";
				if(s[i]-'0')cout<<s[i]<<s[j];
				else cout<<s[j];return 0;

			}
			for(k=j+1;k<n;k++)
			{
				if(check(s[i]-'0',s[j]-'0',s[k]-'0'))
				{
					cout<<"YES\n";
					if(s[i]-'0')cout<<s[i]<<s[j]<<s[k];
					else 
					{
							if(s[j]-'0')cout<<j<<k;
							else cout<<k;
					}return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}