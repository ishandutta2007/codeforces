/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(LL i=0;i<n;i++)
#define repn(i,n) for(LL i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,m,must=0;
LL a[100010],t[100010],num[100010];
vector <LL> numm[100010],all;

int main()
{
	cin>>n>>m;
	repn(i,n)
	{
		cin>>a[i];
		num[a[i]]++;
		numm[a[i]].pb(i);
	}
	repn(i,n) cin>>t[i];
	repn(i,m)
	{
		if(num[i]==0) must++;
		else
		{
			//cout<<i<<' '<<num[i]<<endl;
			vector <LL> can;
			rep(j,num[i]) can.pb(t[numm[i][j]]);
			sort(can.begin(),can.end());
			rep(j,num[i]-1) all.pb(can[j]);//,cout<<t[can[j]]<<endl;
			//cout<<endl;
		}
	}
	sort(all.begin(),all.end());
	LL ans=0;
	//rep(i,ans.size()) cout<<
	rep(i,must) ans+=all[i];
	cout<<ans<<endl;
	rt0;
}