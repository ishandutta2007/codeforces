#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 
#define mkp make_pair
#define fi first
#define se second
int n;
int dp[100004],fr[100004];
map<pii,pii>mp;
int ans,pos,l[100004];
vector<int>res;
void dfs(int p){
	if(l[p]>0)dfs(fr[p]);
	res.push_back(p);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int v,c,r;scanf("%d%d%d%d",&v,&c,&l[i],&r);
		if(l[i]==0)dp[i]=v;
		pii go=mkp(l[i],r+c);
		if(mp.find(go)!=mp.end()){
			pii ret=mp[go];
			ret.fi+=v;
			if(dp[i]<ret.fi)dp[i]=ret.fi,fr[i]=ret.se;
		}
		pii GO=mkp(l[i]+c,r),ADD=mkp(dp[i],i);
		if(dp[i]>0)mp[GO]=max(mp[GO],ADD);
		if(r==0&&ans<dp[i])ans=dp[i],pos=i;
	}
	if(ans<1){puts("0\n");return 0;}
	dfs(pos); 
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++)printf("%d ",res[i]);
}