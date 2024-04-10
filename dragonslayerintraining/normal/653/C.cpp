#include <cstdio>
#include <algorithm>
#include <set>

const int INF=1e9+7;

int as[150005];
int bad=0;
int N;

bool violate(int i){
  return (i&1)?(as[i]>=as[i+1]):(as[i]<=as[i+1]);
}

void constrain(int i,int v){
  bad+=violate(i)*v;
}

int cnt=0;
std::set<std::pair<int,int> > checked;

void check(int x,int y){
  if(x>y) std::swap(x,y);
  if(x==y||checked.count(std::make_pair(x,y))) return;
  checked.insert(std::make_pair(x,y));
  std::set<int> near;
  near.insert(x-1);
  near.insert(x);
  near.insert(y-1);
  near.insert(y);
  for(int z:near){
    constrain(z,-1);
  }
  std::swap(as[x],as[y]);
  for(int z:near){
    constrain(z,1);
  }
  if(bad==0) cnt++;
  for(int z:near){
    constrain(z,-1);
  }
  std::swap(as[x],as[y]);
  for(int z:near){
    constrain(z,1);
  }
}

void check(int i){
  if(i<=0||i>N) return;
  for(int j=1;j<=N;j++){
    check(i,j);
  }
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  as[0]=INF;
  as[N+1]=((N+1)&1)?-INF:INF;
  for(int i=0;i<=N;i++){
    constrain(i,1);
  }
  int violations=0;
  for(int i=0;i<=N;i++){
    if(violate(i)){
      if(++violations>4){
	printf("0\n");
	return 0;
      }
      check(i);
      check(i+1);
    }
  }
  printf("%d\n",cnt);
  return 0;
}