#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,d,a[100010],sum1[100010],sum2[100010];
vector<int> v1,v2;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	ans+=a[n];n--;
	v1.push_back(0ll);v2.push_back(0ll);
	for(int i=1;i<=n;i++){
		if(a[i]<=m) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	for(int i=v1.size()-1;i>=0;i--) sum1[i]=sum1[i+1]+v1[i];
	for(int i=v2.size()-1;i>=0;i--) sum2[i]=sum2[i+1]+v2[i];
	int id=max(0ll,(int)v2.size()-n/(d+1));
	int mx=sum2[id];
	for(int i=1;i<=v1.size();i++){
	    id=max(0ll,(int)v2.size()-(n-i)/(d+1));
		mx=max(mx,sum1[v1.size()-i]+sum2[id]);
	}
	ans+=mx;
	cout<<ans<<endl;
	return 0;
}