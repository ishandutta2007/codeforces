#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,int> >v;
int n;long long l,r,ans[200003],k;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&l,&r);
		v.push_back(make_pair(l,1));
		v.push_back(make_pair(r+1,-1));
	}
	v.push_back(make_pair(0,0));
	sort(v.begin(),v.end());
	for(int i=1;i<=v.size();i++){
		ans[k]+=v[i].first-v[i-1].first;
		k+=v[i].second;
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}