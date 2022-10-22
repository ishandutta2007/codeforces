#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int N;
set<int> v[1010];
int dist[1010];
vector<int> d(1010,-1),d1(1010);
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      v[a].insert(b);
      v[b].insert(a);
    }
    int pos=0;
    queue<pair<int,int> >q;
    while(1){
      fill(d1.begin(),d1.end(),-1);
      q.push({pos,0});
      while(!q.empty()){
        int p=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(d1[p]!=-1)continue;
        pos=p;
        d1[p]=dist;
        for(int x:v[p])q.push({x,dist+1});
      }
      fill(d.begin(),d.end(),-1);
      int a;
      q.push({pos,0});
      while(!q.empty()){
        int p=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(d[p]!=-1)continue;
        a=p;
        d[p]=dist;
        for(int x:v[p])q.push({x,dist+1});
      }
      fill(d1.begin(),d1.end(),-1);
      q.push({a,0});
      while(!q.empty()){
        int p=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(d1[p]!=-1)continue;
        d1[p]=dist;
        for(int x:v[p])q.push({x,dist+1});
      }
      int dim=d[a];
      cout<<"? "<<pos+1<<" "<<a+1<<endl;
      int k;
      cin>>k;
      k--;
      vector<int> m;
      for(int h:v[k]){
        if(d[h]+d1[h]==dim)m.push_back(h);
      }
      for(int i=0;i<m.size();i++)v[k].erase(m[i]);
      pos=k;
      if(v[k].size()==0)break;
    }
    cout<<"! "<<pos+1<<endl;
    return 0;
}