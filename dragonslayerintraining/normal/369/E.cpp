#include <cstdio>
#include <vector>

int ans[300005];

std::vector<int> points[1000006];

int bit[1000006];
std::vector<std::pair<int,int> > qs[1000006];

void add(int i,int v){
  for(i++;i>0;i-=(i&-i)){
    bit[i]+=v;
  }
}

int query(int i){
  int res=0;
  for(i++;i<1000006;i+=(i&-i)){
    res+=bit[i];
  }
  return res;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    points[R].push_back(L);
  }
  for(int q=0;q<M;q++){
    int K;
    scanf("%d",&K);
    std::vector<int> ps({0});
    while(K--){
      int P;
      scanf("%d",&P);
      ps.push_back(P);
    }
    ps.push_back(1000001);
    for(int i=1;i<ps.size();i++){
      qs[ps[i]-1].push_back({ps[i-1]+1,q});
    }
  }
  for(int y=0;y<=1000001;y++){
    for(int x:points[y]){
      add(x,1);
    }
    for(auto q:qs[y]){
      ans[q.second]+=query(q.first);
    }
  }
  for(int i=0;i<M;i++){
    printf("%d\n",N-ans[i]);
  }
  return 0;
}