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
#define findMax max_element
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
	string str;
	cin>>str;
	set<ll>  s[26];
	ll check[100005],num,q;
	for(auto i=0;str[i];i++)
	{
		check[i]=str[i]-'a';
		s[str[i]-'a'].insert(i);
	}
	char c;
	cin>>q;
	ll pos,ans,l,r;
	while(q--)
	{
		cin>>num;
		if(num==1)
		{
			cin>>pos>>c;
			s[check[pos-1]].erase(pos-1);
			s[c-'a'].insert(pos-1);
			check[pos-1]=c-'a';
		}
		else
		{
			cin>>l>>r;
			ans=0;
			for(auto i=0;i<26;i++)
			{
				auto it=s[i].find(l-1);
				if(it==s[i].end())
					it=s[i].upper_bound(l-1);
				if(it!=s[i].end())
				{
					if(*it<r)
						ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}