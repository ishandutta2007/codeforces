#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > sale,scende;
bool vis[110][61000];
int memo[110][61000];
int N;
int sol(int pos,int x){
  if(x<0)return -1000000;
  if(pos>=scende.size())return 0;
  if(vis[pos][x])return memo[pos][x];
  vis[pos][x]=1;
  if(scende[pos].first>x)return memo[pos][x]=sol(pos+1,x);
  return memo[pos][x]=max(sol(pos+1,x),sol(pos+1,x+scende[pos].second)+1);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int K;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			int a,b;
			cin>>a>>b;
			if(b>=0)sale.push_back({a,b});
			else scende.push_back({a,b});
		}
		sort(sale.begin(),sale.end());
		int tot=0;
		for(int i=0;i<sale.size();i++){
			if(sale[i].first>K)continue;
			K+=sale[i].second;
			tot++;
		}
		sort(scende.begin(),scende.end(),[](pair<int,int> a,pair<int,int> b){
       return a.first+a.second>b.first+b.second;
    });
		tot+=sol(0,K);
		cout<<tot;
		return 0;
}