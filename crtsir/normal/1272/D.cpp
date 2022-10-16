#include<bits/stdc++.h>
using namespace std;
int a[200003],n,cnt[200003],ans;
vector<pair<int,int> >v;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1])
			cnt[i]=1,
			v.push_back(make_pair(cnt[i-1],i-1));
		else
			cnt[i]=cnt[i-1]+1,
			ans=max(ans,cnt[i]);
	}
	v.push_back(make_pair(cnt[n],n));
	for(int i=1;i<v.size();i++)
		if(a[v[i-1].second-1]<a[v[i-1].second+1]||a[v[i-1].second]<a[v[i-1].second+2])
			ans=max(ans,v[i].first+v[i-1].first-1);
	cout<<ans;
}