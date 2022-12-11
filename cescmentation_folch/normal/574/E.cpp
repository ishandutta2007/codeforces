#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef priority_queue<pi> pqi;

int main(){
  int n,m;
  cin>>n;
  vvi G(n);
  vi P(n,0);
  vvi k(n,vi(5,0));
  pqi Q;
  for(int i = 1;i < n;++i){
    int x,y;
    cin>>x>>y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
    ++P[x];
    ++P[y];
  }
  for(int i = 0;i < n;++i){
    if(P[i] == 1){
      Q.push(pi(-1,i));
    }
  }
  vi T = P;
  bool xec = true;
  while(!Q.empty()){
    int x = Q.top().Y;
    Q.pop();
    if(k[x][1] > 0 or k[x][2] > 2){ 
      xec = false;
      k[x][0] = 1;
    }
    else if(k[x][2] == 1) k[x][0] = 2;
    else if(k[x][2] == 2) k[x][0] = 1;
    else if(k[x][3] > 0 or k[x][4] > 2) k[x][0] = 2;
    else if(k[x][4] == 2) k[x][0] = 3;
    else k[x][0] = 4;
    int count = 0;
    for(int i = 0;i <G[x].size();++i){
      int y = G[x][i];
      if(P[y] > 1){
	--P[y];
	k[y][k[x][0]]++;
	if(P[y] == 1) Q.push(pi(-T[y],y));
	++count;
      }
    }
    if(count == 0 and k[x][0] == 1){
      for(int i = 0;i < G[x].size();++i){
	int y = G[x][i];
	if(k[y][0] == 2) ++count;
      }
      if(count > 2) xec = false;
    }
    else if(count == 0 and k[x][0] == 2){
      for(int i = 0;i < G[x].size();++i){
	int y = G[x][i];
	if(k[y][0] == 1) xec = false;
      }
    }
  }
  int count = 0;
  /*
  for(int i = 0;i < n;++i){
    if(k[i][0] == 1) ++count;
    cout<<i<<" "<<k[i][0]<<endl;
  }
  */
  if(count > 1) xec = false;
  if(xec) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}