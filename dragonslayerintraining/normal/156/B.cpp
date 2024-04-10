#include <iostream>

int truth[100001];
int negatives=0;
int as[100001];
int suspect[100001];
int total_suspects=0;

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=1;i<=N;i++){
    int X;
    std::cin>>X;
    as[i]=X;
    if(X>0){
      truth[X]++;
    }else{
      negatives++;
      truth[-X]--;
    }
  }
  for(int i=1;i<=N;i++){
    if(truth[i]+negatives==M){
      suspect[i]++;
      total_suspects++;
    }
  }
  for(int i=1;i<=N;i++){
    int type=0;
    int X=as[i];
    if(X>0){
      if(suspect[X]>0){
	type|=1;
      }
      if(total_suspects-suspect[X]>0){
	type|=2;
      }
    }else if(X<0){
      if(suspect[-X]>0){
	type|=2;
      }
      if(total_suspects-suspect[-X]>0){
	type|=1;
      }
    }
    switch(type){
    case 1:
      std::cout<<"Truth"<<std::endl;
      break;
    case 2:
      std::cout<<"Lie"<<std::endl;
      break;
    case 3:
      std::cout<<"Not defined"<<std::endl;
      break;
    }
  }
  return 0;
}