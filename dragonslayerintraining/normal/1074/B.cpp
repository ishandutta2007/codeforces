#include <cstdio>
#include <set>
#include <vector>

struct Tree{
  std::vector<std::vector<int> > adj;
  std::vector<bool> mine;
  Tree(int N):adj(N),mine(N){
  }
  void add(int A,int B){
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  int explore(int X,int parent=-1){
    if(mine[X]) return X;
    for(int child:adj[X]){
      if(child==parent) continue;
      int tmp=explore(child,X);
      if(tmp!=-1) return tmp;
    }
    return -1;
  }
};

int query(char t,int X){
  printf("%c %d\n",t,X+1);
  fflush(stdout);
  int Y;
  scanf("%d",&Y);
  return Y-1;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    int N;
    scanf("%d",&N);
    struct Tree tree(N);
    for(int i=0;i<N-1;i++){
      int A,B;
      scanf("%d %d",&A,&B);
      A--,B--;
      tree.add(A,B);
    }
    int K1;
    scanf("%d",&K1);
    for(int i=0;i<K1;i++){
      int X;
      scanf("%d",&X);
      X--;
      tree.mine[X]=true;
    }
    int K2;
    scanf("%d",&K2);
    std::set<int> lichen;
    for(int i=0;i<K2;i++){
      int X;
      scanf("%d",&X);
      X--;
      lichen.insert(X);
    }
    int X=query('B',*lichen.begin());
    if(tree.mine[X]){
      printf("C %d\n",X+1);
      fflush(stdout);
      continue;
    }
    int Y=tree.explore(X);
    int Z=query('A',Y);
    if(lichen.count(Z)){
      printf("C %d\n",Y+1);
    }else{
      printf("C -1\n");
    }
    fflush(stdout);
  }
  return 0;
}