#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    map<int,bool>vis;
    int tot=0;
    vector<int> ans;
    queue<pair<int,int> >q;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      q.push({a,0});
    }
    int presi=0;
    while(q.size()){
      int pos=q.front().first;
      int d=q.front().second;
      q.pop();
      if(vis.count(pos-1)==0)q.push({pos-1,d+1});
      if(vis.count(pos+1)==0)q.push({pos+1,d+1});
      if(vis[pos])continue;
      vis[pos]=1;
      presi++;
      tot+=d;
      if(d!=0)ans.push_back(pos);
      if(presi==N+M)break;
    }
    cout<<tot<<'\n';
    for(int x:ans)cout<<x<<" ";
}