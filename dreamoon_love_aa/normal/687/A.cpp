#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int cc,n,m,j,v[1111111],used[1234567];
vector<int>e[1234567];
void dfs(int x){
  used[x]=1;
  
  for(int i=0;i<e[x].size();i++){
    int y=e[x][i];
    if(used[y]){
      if(!(v[x]^v[y])){puts("-1");exit(0);}
    }
    else{
      v[y]=v[x]^1;
      cc+=v[y];
      dfs(y);
    }
  }
}
main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
    if(!used[i])dfs(i);
  printf("%d\n",cc);
  for(int i=1;i<=n;i++)
    if(v[i])printf("%d ",i);
  printf("\n%d\n",n-cc);
  for(int i=1;i<=n;i++)
    if(!v[i])printf("%d ",i);
}