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

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<string,int> m00,m01,m10,m11;
	int i,t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s,temp;
		m00.clear();m11.clear();m10.clear();m01.clear();
		for(i=0;i<n;++i)
		{
			cin>>s;
			if(s[0]=='1' && s.back()=='1')m11[s]=i+1;
			else if(s[0]=='1' && s.back()=='0')m10[s]=i+1;
			else if(s[0]=='0' && s.back()=='1')m01[s]=i+1;
			else m00[s]=i+1;
		}
		vector<int> ans;
		if(m00.size()>=1 && m11.size()>=1 && m10.empty()&&m01.empty())
		{
			cout<<-1<<endl;continue;	
		}
		int l=m01.size(),r=m10.size();
		if(l==r || abs(l-r)==1)
		{
			cout<<0<<endl<<endl;continue;
		}
		if(l>r)
		{
			int k=(l-r)>>1;
			for(auto j:m01)
			{
				if(k==0)break;
				temp=j.F;reverse(all(temp));
				if(!m10.count(temp))
				{
					ans.pb(j.S);--k;
				}
			}
			if(k>0)
			{
				cout<<-1<<endl;continue;
			}
		}
		else
		{
			int k=(r-l)>>1;
			for(auto j:m10)
			{
				if(k==0)break;
				temp=j.F;reverse(all(temp));
				if(!m01.count(temp))
				{
					ans.pb(j.S);--k;
				}
			}
			if(k>0)
			{
				cout<<-1<<endl;continue;
			}
		}
		cout<<ans.size()<<endl;
		for(auto j:ans)cout<<j<<" ";
			cout<<endl;
	}
}