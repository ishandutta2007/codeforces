#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i;
	string s;
	bool done;
	bool vis[26];
	cin>>n;
	set<char> se;
	while(n--)
	{
		cin>>s;
		se.clear();
		for(i=0;i<26;i++)vis[i]=false;
			done=false;
		for(i=0;s[i];i++)
		{
			if(vis[s[i]-'a'])
			{
				done=true;
				cout<<"No\n";
				break;
			}
			else 
				{
					vis[s[i]-'a']=true;
					se.insert(s[i]);
				}
		}
		if(done)continue;
		auto it=se.end();--it;
		if(*it-*se.begin()+1!=se.size())cout<<"No\n";
		else cout<<"Yes\n";
	}   
	return 0;

}