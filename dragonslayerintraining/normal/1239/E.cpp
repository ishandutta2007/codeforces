#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cassert>

std::bitset<50000*25> dp[50][25];
int as[50];

std::vector<int> list[2];

void recover(int i,int cnt,int s){
  assert(dp[i][cnt].test(s));
  if(i==0) return;
  if(dp[i-1][cnt].test(s)){
    recover(i-1,cnt,s);
    list[0].push_back(as[i+1]);
  }else{
    recover(i-1,cnt-1,s-as[i+1]);
    list[1].push_back(as[i+1]);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  int sum=0;
  for(int i=0;i<N*2;i++){
    scanf("%d",&as[i]);
    sum+=as[i];
  }
  std::sort(as,as+N*2);
  sum-=as[0];
  sum-=as[1];
  list[0].push_back(as[0]);
  list[1].push_back(as[1]);
  dp[0][0].set(0);
  for(int i=2;i<N*2;i++){
    for(int cnt=0;cnt<N;cnt++){
      dp[i-1][cnt]=dp[i-2][cnt];
      if(cnt){
	dp[i-1][cnt]|=(dp[i-2][cnt-1]<<as[i]);
      }
    }
  }
  for(int s=(sum+1)/2;s<50000*25;s++){
    if(dp[N*2-2][N-1].test(s)){
      recover(N*2-2,N-1,s);
      break;
    }
  }
  std::reverse(list[1].begin(),list[1].end());
  for(int l=0;l<2;l++){
    assert(list[l].size()==N);
    for(int i=0;i<N;i++){
      if(i) printf(" ");
      printf("%d",list[l][i]);
    }
    printf("\n");
  }
}