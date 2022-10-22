#include<bits/stdc++.h>
using namespace std;
const int N=4000;
int t,n,l[N],r[N];
vector<int>rg[N*2];
vector<int>val;
vector<vector<int>>dp;
int calc(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	dp[l][r]=0;
	if(l>r)return dp[l][r];
	bool add=count(rg[l].begin(),rg[l].end(),r);
	dp[l][r]=max(dp[l][r],add+(l+1>r?0:calc(l+1,r)));
	for(auto nr:rg[l]){
		if(nr>=r)continue;
		dp[l][r]=max(dp[l][r],add+calc(l,nr)+(nr+1>r?0:calc(nr+1,r)));
	}return dp[l][r];
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;val.clear();
		for(int i=1;i<=n;i++)
			cin>>l[i]>>r[i],
			val.push_back(l[i]),
			val.push_back(r[i]);
		sort(val.begin(),val.end());
		val.resize(unique(val.begin(),val.end())-val.begin());
		int siz=val.size();
		for(int i=0;i<siz;i++)
			rg[i].clear();
		for(int i=1;i<=n;i++) {
			l[i]=lower_bound(val.begin(),val.end(),l[i])-val.begin();
			r[i]=lower_bound(val.begin(),val.end(),r[i])-val.begin();
			rg[l[i]].push_back(r[i]);
		}
		dp=vector<vector<int>>(siz,vector<int>(siz,-1));
		cout<<calc(0,val.size()-1)<<endl;
	}
}