#include <cstdio>
#include <vector>

std::vector<int> children[100005];

int ts[100005];
int args[100005][2];

int books[1005][1005];
int inverted[1005];
int rowsum[1005];
int total;

int ans[100005];
int N,M;

int get(int i,int j){
  return books[i][j]^inverted[i];
}

int getrowsum(int i){
  return inverted[i]?(M-rowsum[i]):rowsum[i];
}

void set(int i,int j,int v){
  total-=getrowsum(i);
  rowsum[i]-=books[i][j];
  books[i][j]=v^inverted[i];
  rowsum[i]+=books[i][j];
  total+=getrowsum(i);
}

void invertrow(int i){
  total-=getrowsum(i);
  inverted[i]^=1;
  total+=getrowsum(i);
}

void dfs(int node);

void recurse(int node){
  //printf("NODE %d\n",node);
  ans[node]=total;
  for(int child:children[node]){
    dfs(child);
  }
}

void dfs(int node){
  //printf("DFS(%d)\n",node);
  int i=args[node][0];
  int j=args[node][1];
  switch(ts[node]){
  case 1:case 2:{
    int tmp=get(i,j);
    set(i,j,(ts[node]==1)?1:0);
    recurse(node);
    set(i,j,tmp);
    break;
  }
  case 3:{
    invertrow(i);
    recurse(node);
    invertrow(i);
    break;
  }
  default:{
    recurse(node);
  }
  }
}

int main(){
  int Q;
  scanf("%d %d %d",&N,&M,&Q);
  for(int i=1;i<=Q;i++){
    scanf("%d",&ts[i]);
    int from=i-1;
    switch(ts[i]){
    case 1:
    case 2:
      scanf("%d %d",&args[i][0],&args[i][1]);
      break;
    case 3:
      scanf("%d",&args[i][0]);
      break;
    case 4:
      scanf("%d",&from);
      break;
    }
    children[from].push_back(i);
  }
  dfs(0);
  for(int i=1;i<=Q;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}