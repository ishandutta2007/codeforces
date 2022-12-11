#include<cmath>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N=2e5+50;
int T,n,m,dis[N],num[N];bool vis[N];
vector<int>v[N];
priority_queue<pair<int,int> >q;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1,x,y;i<=m;i++){
    scanf("%d%d",&x,&y);
    v[y].pb(x);num[x]++;
  }
  memset(dis,0x3f,sizeof(dis));
  dis[n]=0;q.push(mp(0,n));
  while(q.size()){
    int x=q.top().second;q.pop();
    if(vis[x])continue;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
      int y=v[x][i];
      if(dis[x]+num[y]<dis[y]){
        dis[y]=dis[x]+num[y];
        q.push(mp(-dis[y],y));
      }
      num[y]--;
    }
  }
  cout<<dis[1]<<endl;
  return 0;
}