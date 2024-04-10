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

int main(){
  vvi T(4000,vi(4000,0));
  int n,m;
  cin>>n>>m;
  vvi G(n);
  vi P(n,0);
  for(int i = 0;i < m;++i){
    int x,y;
    cin>>x>>y;
    --x;
    --y;
    T[x][y] = T[y][x] = 1;
    P[x]++;
    P[y]++;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int r = 4000;
  for(int i = 0;i < n;++i){
    for(int j = 0;j < G[i].size();++j){
      for(int w = j+1;w < G[i].size();++w){
	int x = G[i][j];
	int y = G[i][w];
	if(T[x][y]){
	  r = min(r,P[i]+P[x]+P[y]-6);
	}
      }
    }
  }
  if(r == 4000) cout<<-1<<endl;
  else cout<<r<<endl;
}