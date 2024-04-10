#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
unordered_map<int,vector<pair<int,int> > > p;
set<int> vis;
vector<int> memo(4000000);
vector<pair<int,int> > ans;
int dp(int sum,int pos){
  if(pos>=p[sum].size())return 0;
  if(memo[pos])return memo[pos];
  pair<int,int> k={p[sum][pos].second+1,-1};
  int prox=lower_bound(p[sum].begin(),p[sum].end(),k)-p[sum].begin();
  return memo[pos]=max(dp(sum,pos+1),dp(sum,prox)+1);
}
void sol(int sum,int pos){
  if(pos>=p[sum].size())return ;
  pair<int,int> k={p[sum][pos].second+1,-1};
  int prox=lower_bound(p[sum].begin(),p[sum].end(),k)-p[sum].begin();
  if(memo[prox]+1>memo[pos+1])ans.push_back(p[sum][pos]);
  sol(sum,(memo[prox]+1>memo[pos+1]?prox:pos+1));
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		v.push_back(0);
		for(int i=0;i<N;i++){
      int a;
      cin>>a;
      v.push_back(a+v.back());
		}
		for(int i=1;i<=N;i++){
      for(int j=i;j<=N;j++){
        p[v[j]-v[i-1]].push_back({i,j});
        vis.insert(v[j]-v[i-1]);
      }
		}
		int ma=0,best;
		for(int a:vis){
      sort(p[a].begin(),p[a].end());
      int o=dp(a,0);
      if(o>ma){
        ma=o;
        best=a;
      }
      fill(memo.begin(),memo.begin()+p[a].size()+100,0);
		}
		dp(best,0);
		sol(best,0);
		cout<<ma<<endl;
		for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}