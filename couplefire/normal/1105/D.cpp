#include<bits/stdc++.h>
using namespace std;
 
const int MXN=1005;
 
int s[10],cnt[10];
char grid[MXN][MXN];
int player[MXN][MXN];
queue<array<int,3>>Q[10];
 
int main(){
  ios::sync_with_stdio(0),cin.tie(0);
  int n,m,p;
  cin>>n>>m>>p;
  for(int i=1;i<=p;++i)cin>>s[i];
  for(int i=1;i<=n;++i){
    cin>>grid[i]+1;
    for(int j=1;j<=m;++j){
      if(isdigit(grid[i][j])){
        int p=grid[i][j]-'0';
        Q[p].push({s[p]-1,i,j});
        grid[i][j]='.';
      }
    }
  }
  for(int tt=0;tt<=n*m;++tt){
    for(int i=1;i<=p;++i){
      auto&q=Q[i];
      for(;q.size();q.pop()){
        auto[t,x,y]=q.front();
        if(grid[x][y]!='.')continue;
        if(player[x][y])continue;
        if(t/s[i]!=tt)break;
        player[x][y]=i;
        cnt[i]++;
        q.push({t+1,x+1,y});
        q.push({t+1,x-1,y});
        q.push({t+1,x,y+1});
        q.push({t+1,x,y-1});
      }
    }
  }
  for(int i=1;i<=p;++i){
    cout<<cnt[i]<<' ';
  }
  cout<<'\n';
}