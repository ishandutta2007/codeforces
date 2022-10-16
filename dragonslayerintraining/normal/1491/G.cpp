#include <cstdio>
#include <vector>

int cs[200005];
int inv[200005];

bool vis[200005];

std::vector<std::pair<int,int> > moves;

void flip(int x,int y){
  moves.push_back({x,y});
  std::swap(cs[x],cs[y]);
  std::swap(inv[cs[x]],inv[cs[y]]);
}

void gobble(int x,int y){
  //x and y are in same cycle and have wrong parity
  while(cs[x]!=y){
    flip(x,cs[x]);
  }
  while(cs[y]!=x){
    flip(y,cs[y]);
  }
  flip(x,y);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&cs[i]);
    inv[cs[i]]=i;
  }
  std::vector<int> cycles;
  for(int i=1;i<=N;i++){
    if(!vis[i]){
      for(int j=i;!vis[j];j=cs[j]){
	vis[j]=true;
      }
      if(i!=cs[i]){
	cycles.push_back(i);
      }
    }
  }
  while(cycles.size()>=2){
    int x=cycles.back();
    cycles.pop_back();
    int y=cycles.back();
    cycles.pop_back();
    flip(x,y);
    gobble(x,y);
  }
  if(cycles.size()>=1){
    int x=cycles.back();
    cycles.pop_back();
    if(cs[cs[x]]==x){
      //length 2
      int y=1;
      while(y==x||y==cs[x]) y++;
      flip(x,y);
      gobble(x,y);
    }else{
      int y=cs[x];
      int z=cs[y];
      flip(y,z);
      flip(x,z);
      gobble(y,z);
    }
  }
  printf("%d\n",(int)moves.size());
  for(auto m:moves){
    printf("%d %d\n",m.first,m.second);
  }
}