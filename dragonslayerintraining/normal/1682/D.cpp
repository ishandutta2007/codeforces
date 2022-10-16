#include <cstdio>
#include <vector>

char str[200005];

void solve(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  std::vector<int> odd;
  for(int i=0;i<N;i++){
    if(str[i]=='1'){
      odd.push_back(i);
    }
  }
  if(odd.empty()||odd.size()%2==1){
    printf("NO\n");
    return;
  }
  std::vector<std::pair<int,int> > edges;
  for(int j=1;j<odd.size();j++){
    edges.emplace_back(odd[0],odd[j-1]+1);
    for(int x=odd[j-1]+1;x<odd[j];x++){
      edges.emplace_back(x,x+1);
    }
  }
  edges.back().second=(odd[0]+N-1)%N;
  for(int x=(odd[0]+N-1)%N;x!=odd.back();x=(x+N-1)%N){
    edges.emplace_back(x,(x+N-1)%N);
  }
  printf("YES\n");
  for(auto e:edges){
    printf("%d %d\n",e.first+1,e.second+1);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}