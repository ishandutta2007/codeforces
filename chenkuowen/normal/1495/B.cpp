#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int a[N],b[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
		b[i]=a[i]<a[i+1];
	vector<pair<int,int> > c; c.push_back(make_pair(b[1],1));
	for(int i=2;i<n;++i)
		if(b[i]==b[i-1]) c[c.size()-1].second++;
		else c.push_back(make_pair(b[i],1));
	int mx=0;
	for(auto x:c) mx=max(mx,x.second);
	vector<pair<int,int> > d;
	for(int i=0;i<c.size();++i)
		if(c[i].second==mx) d.push_back(make_pair(c[i].first,i));
	if(d.size()==2&&d[0].second+1==d[1].second&&(~mx&1)&&d[1].first==0) puts("1");
	else puts("0");
	return 0;
}