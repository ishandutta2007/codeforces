#include<bits/stdc++.h>
#define int long long
const int N=5005;
using namespace std;

int n,m;
vector<int>a[N];

int calc(int x){
	int na=0,c=a[1].size();
	priority_queue<int>q;
	for(int i=2;i<=m;i++){
		for(int j=0;j<(int)a[i].size()-x+1;j++)
			na+=a[i][j],c++;
		for(int j=max((int)a[i].size()-x+1,0ll);j<a[i].size();j++)
			q.push(-a[i][j]);
	}
	while(c<x)	
		na-=q.top(),q.pop(),c++;
	return na;
}

main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	for(int i=1;i<=m;i++)
		sort(a[i].begin(),a[i].end());
	int ans=1e18;
	for(int i=1;i<=n;i++)
		ans=min(ans,calc(i));
	cout<<ans<<endl;
}