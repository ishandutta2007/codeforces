#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int sol[100010];
set<int>v[100100];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      v[a].insert(b);
      v[b].insert(a);
    }
    int tot=0;
    vector<bool> vis(100010,0);
    queue<int>q;
    for(int i=0;i<N;i++){
      q.push(i);
    }
    while(q.size()){
      int i=q.front();
      q.pop();
      if(vis[i])continue;
      if(v[i].size()==1 && v[*v[i].begin()].size()>1)continue;
      //q.push(i);
      int k=0;
      for(int x:v[i]){
        if(v[x].size()>1)k++;
      }
      if(k>1)continue;
      vis[i]=1;
      vector<int>p={i};
      for(int x:v[i]){
        if(v[x].size()==1){
          p.push_back(x);
          vis[x]=1;
        }
        v[x].erase(i);
        if(v[x].size()==1){
          q.push(*v[x].begin());
        }
        if(v[x].size()>1){
          q.push(x);
        }
      }
      v[i].clear();
      for(int i=0;i<p.size();i++){
        sol[p[i]]=p[(i+1)%p.size()];
      }
      tot+=2*(p.size()-1);
    }
    cout<<tot<<'\n';
    for(int i=0;i<N;i++)cout<<sol[i]+1<<" ";
}