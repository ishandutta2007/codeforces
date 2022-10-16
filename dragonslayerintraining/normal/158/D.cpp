#include <iostream>
#include <vector>

int attract[20000];
int N;

std::vector<std::pair<int,int> > factors;

void factor(int num){
  int num2=num;
  for(int i=2;(i*i<=num)&&(num2>1);i++){
    if(num2%i==0){
      int cnt=0;
      while(num2%i==0){
	num2/=i;
	cnt++;
      }
      factors.push_back(std::make_pair(i,cnt));
    }
  }
  if(num2>1){
    factors.push_back(std::make_pair(num2,1));
  }
}

std::vector<int> seq;

int best=-1e9;

void test(int range){
  if(N/range<3){
    return;
  }
  for(int i=0;i<N;i++){
    seq[i]=attract[i];
    if(i>=range){
      seq[i]+=seq[i-range];
    }
    if(i>=N-range){
      best=std::max(best,seq[i]);
    }
  }
}

void dfs(int i,int ac){
  if(i==factors.size()){
    test(ac);
    return;
  }
  for(int k=0;k<=factors[i].second;k++){
    dfs(i+1,ac);
    ac*=factors[i].first;
  }
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>attract[i];
  }
  factor(N);
  seq.resize(N);
  dfs(0,1);
  std::cout<<best<<std::endl;
  return 0;
}