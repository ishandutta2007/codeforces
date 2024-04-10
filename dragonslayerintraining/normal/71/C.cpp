#include <iostream>
#include <vector>

std::vector<int> factors;

int mood[100000];
int N;

void calcfactors(int num){
  for(int i=3;i<=num;i++){
    if(num%i==0){
      factors.push_back(i);
      while(num%i==0){
	num/=i;
      }
    }
  }
}

bool lucky(){
  calcfactors(N);
  for(int i=0;i<factors.size();i++){
    int skip=N/factors[i];
    for(int j=0;j<skip;j++){
      for(int k=j;;k+=skip){
	if(k>=N){
	  return true;
	}
	if(mood[k]==0){
	  break;
	}
      }
    }
  }
  return false;
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>mood[i];
  }
  if(lucky()){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}