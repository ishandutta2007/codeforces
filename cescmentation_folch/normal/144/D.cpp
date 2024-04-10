#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vii> vvii;

#define X first
#define Y second

int main(){
  int n,m,s;
  cin>>n>>m>>s;
  
  vvii G(n+1);
  vi D(n+1,-1);
  
  for(int i = 0;i < m;++i){
    int x,y,d;
    cin>>x>>y>>d;
    
    G[x].push_back(ii(y,d));
    G[y].push_back(ii(x,d));
  }
  
  int l;
  cin>>l;
  
  D[s] = 0;
  priority_queue<ii> Q;
  Q.push(ii(0,s));
  
  while(!Q.empty()){
    ii k = Q.top();
    Q.pop();
    
    if(D[k.Y] < -k.X and D[k.Y] != -1){
      continue;
    }
    
    for(int i = 0;i < G[k.Y].size();++i){
      int y = G[k.Y][i].X;
      int d = G[k.Y][i].Y;
      
      if(D[y] == -1 or D[y] > D[k.Y]+d){
	Q.push(ii(-(D[k.Y]+d),y));
	D[y] = D[k.Y]+d;
      }
    }
  }
  
  int count = 0;
  
  for(int i = 1;i <= n;++i){
    if(D[i] == l){ 
      ++count;
    }
    
    for(int j = 0; j < G[i].size();++j){
      int k = G[i][j].X;
      int d = G[i][j].Y;
      
      if(k < i) continue;
      
      if((D[k] > l and l > D[i]) or (D[i] > l and l > D[k])) ++count;
      if(l-D[k] + l-D[i] < d and l > D[k] and l > D[i]) count += 2;
      if(l-D[k] + l-D[i] == d and l > D[k] and l > D[i]) ++count;
      if((l-D[k]< d and D[i] == l and l > D[k]) or (l-D[i]< d and D[k] == l and l > D[i])) ++count;
    }
  }
  
  cout<<count<<endl;
}