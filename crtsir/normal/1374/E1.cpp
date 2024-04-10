#include<bits/stdc++.h>
using namespace std;
int t[200003],cnt[2][200003],n,k,a[200003],b[200003],cntt,ans=2147483647;vector<int>v[4];
int main(){cin>>n>>k;for(int i=1;i<=n;i++)cin>>t[i]>>a[i]>>b[i],v[2*a[i]+b[i]].push_back(t[i]);
	v[3].push_back(0);for(int i=0;i<4;i++)sort(v[i].begin(),v[i].end());
	for(int i=0;i<v[1].size();i++)cnt[0][i+1]=cnt[0][i]+v[1][i];
	for(int i=0;i<v[2].size();i++)cnt[1][i+1]=cnt[1][i]+v[2][i];
	for(int i=0;i<min(int(v[3].size()),k+1);i++)cntt+=v[3][i];
	for(int i=min(k,int(v[3].size()-1));i>-1;i--)if(k-i<=v[1].size()&&k-i<=v[2].size())
		ans=min(ans,cntt+cnt[0][k-i]+cnt[1][k-i]),cntt-=v[3][i];
	if(ans!=2147483647)cout<<ans;else cout<<-1;
}