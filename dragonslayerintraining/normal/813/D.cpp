#include <iostream>
#include <map>
#include <tuple>
#include <vector>

int as[5000];

int compress[100002];
int decompress[5000];
int distinct=0;

int dp[5010][5000];

void setmax(int& a,int b){
  a=std::max(a,b);
}

void insert(int a,int b,int len){
  setmax(dp[compress[as[a]]][b],len);
  setmax(dp[5000+as[a]%7][b],len);
  setmax(dp[compress[as[b]]][a],len);
  setmax(dp[5000+as[b]%7][a],len);
}

int main(){
  std::fill(compress,compress+100002,-1);
  for(int i=0;i<5010;i++){
    std::fill(dp[i],dp[i]+5000,-1e9);
  }
  
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    if(compress[as[i]]==-1){
      compress[as[i]]=distinct;
      decompress[distinct]=as[i];
      distinct++;
    }
  }
  int best=0;
  for(int i=0;i<N;i++){
    std::vector<std::tuple<int,int,int> > tmp;
    int single=1;
    for(int j=0;j<i;j++){
      if((as[i]+1==as[j])||(as[i]-1==as[j])||(as[i]%7==as[j]%7)){
	setmax(single,dp[5007][j]+1);
      }
      int top=2;
      if(dp[5007][j]>=0){
	setmax(top,dp[5007][j]+1);
      }
      if((compress[as[i]+1]>=0)&&(dp[compress[as[i]+1]][j]>=0)){
	setmax(top,dp[compress[as[i]+1]][j]+1);
      }
      if((compress[as[i]-1]>=0)&&(dp[compress[as[i]-1]][j]>=0)){
	setmax(top,dp[compress[as[i]-1]][j]+1);
      }
      if(dp[5000+as[i]%7][j]>=0){
	setmax(top,dp[5000+as[i]%7][j]+1);
      }
      tmp.push_back(std::make_tuple(i,j,top));
      //std::cout<<"best("<<i<<","<<j<<")="<<top<<std::endl;
    }
    setmax(dp[5007][i],single);
    //std::cout<<"best("<<i<<")="<<dp[5007][i]<<std::endl;
    for(std::tuple<int,int,int> tuple:tmp){
      insert(std::get<0>(tuple),std::get<1>(tuple),std::get<2>(tuple));
      setmax(best,std::get<2>(tuple));
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}