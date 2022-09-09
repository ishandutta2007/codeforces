#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
map<vector<pair<int,int> >,int> cnt;
vector<pair<int,int> > v,u;
int n,m,i,j,x;
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		scanf("%d",&x); 
		v.clear();
		for(j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				int t=0;
				while(x%j==0)
				{
					x/=j;
					t++;
				}
				t%=m;
				if(t) v.push_back(make_pair(j,t)); 
			}
		}
		if(x>1)
		{
			if(m!=1) v.push_back(make_pair(x,1));
		}
		cnt[v]++;
		//for(j=0;j<v.size();j++) cerr<<v[j].first<<' '<<v[j].second;
		//cerr<<endl;
	}
	for(map<vector<pair<int,int> >,int>::iterator it=cnt.begin();it!=cnt.end();it++)
	{
		u=v=it->first;
		for(i=0;i<u.size();i++) u[i].second=m-u[i].second;
		if(u==v) ans+=1ll*it->second*(it->second-1);
		else ans+=1ll*it->second*cnt[u];
	}
	ans/=2;
	cout<<ans<<endl; 
	return 0;
}