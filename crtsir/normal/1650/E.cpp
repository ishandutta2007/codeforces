#include<bits/stdc++.h>
using namespace std;
int n,d,a[200003];
int calc(int ban){
	vector<int>v;
	for(int i=0;i<=n;i++)
		if(i!=ban)
			v.push_back(a[i]);
	v.push_back(d);
	int ret=1000000007;
	for(int i=1;i<=n;i++)
		ret=min(ret,v[i]-v[i-1]-1);
	return ret;
}
int check(int ban){
	vector<int>v,di;
	for(int i=0;i<=n;i++)
		if(i!=ban)
			v.push_back(a[i]);
	for(int i=1;i<n;i++)
		di.push_back(v[i-1]-v[i]);
	sort(di.begin(),di.end());
	int ret=(-di[0])/2-1;
	for(int i=1;i<n-1;i++)
		ret=min(ret,-di[i]-1);
	return max(ret,calc(ban));
}
int main(){int T;
	cin>>T;
	while(T--){
		cin>>n>>d;
		pair<int,int>nw;nw.first=1000000007;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nw=min(nw,make_pair(a[i]-a[i-1],i));
		}
		int ans=0;
		if(nw.second!=1)
			ans=max(ans,check(nw.second-1));
		ans=max(ans,check(nw.second));
		cout<<ans<<endl;
	}
}