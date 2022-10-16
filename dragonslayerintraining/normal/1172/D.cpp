#include <cstdio>
#include <vector>
#include <array>

int as[1005];
int bs[1005];

int inva[1005];
int invb[1005];

void exchange_a(int i,int j){
  std::swap(as[i],as[j]);
  std::swap(inva[as[i]],inva[as[j]]);
}

void exchange_b(int i,int j){
  std::swap(bs[i],bs[j]);
  std::swap(invb[bs[i]],invb[bs[j]]);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    inva[as[i]]=i;
  }
  for(int i=1;i<=N;i++){
    scanf("%d",&bs[i]);
    invb[bs[i]]=i;
  }
  std::vector<std::array<int,4> > portals;
  for(int i=1;i<=N;i++){
    if(inva[i]!=i||invb[i]!=i){
      portals.push_back({inva[i],i,i,invb[i]});
      exchange_a(i,inva[i]);
      exchange_b(i,invb[i]);
    }
  }
  printf("%d\n",(int)portals.size());
  for(auto it:portals){
    printf("%d %d %d %d\n",it[0],it[1],it[2],it[3]);
  }
  return 0;
}