#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

int as[100];
int ds[100];

std::vector<std::array<int,2> > right,left;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&ds[i]);
    if(ds[i]>0){
      right.push_back({as[i]+ds[i],-i});
    }else{
      left.push_back({-as[i]-ds[i],i});
    }
  }
  std::sort(right.begin(),right.end());
  std::sort(left.begin(),left.end());
  std::vector<int> ord;
  for(auto it:right){
    ord.push_back(-it[1]);
  }
  for(auto it:left){
    ord.push_back(it[1]);
  }
  int cnt=0;
  for(int curr:ord){
    //printf("Update %d\n",curr);
    for(int i=0;i<N;i++){
      if(i==curr) continue;
      if((std::make_pair(as[i],-i)<std::make_pair(as[curr],-curr))!=
	 (std::make_pair(as[i],-i)<std::make_pair(as[curr]+ds[curr],-curr))){
	cnt++;
      }
    }
    as[curr]+=ds[curr];
    //printf("cnt=%d\n",cnt);
  }
  printf("%d\n",cnt);
  return 0;
}