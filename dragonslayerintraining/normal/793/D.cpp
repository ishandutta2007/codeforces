#include <iostream>
#include <vector>
#include <algorithm>

const int INF=80000;

int N,K;

typedef struct Lane{
  int U,V,C;
  Lane(int U,int V,int C):U(U),V(V),C(C){
  }
}Lane;

int path[90][90][90];
int lane[90][90];

std::vector<struct Lane> leftwards[90],rightwards[90];

int main(){
  std::cin>>N>>K;
  N+=2;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      lane[i][j]=INF;
    }
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int U,V,C;
    std::cin>>U>>V>>C;
    lane[U][V]=std::min(lane[U][V],C);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(lane[i][j]<INF){
	if(i<j){
	  rightwards[i].push_back(Lane(i,j,lane[i][j]));
	}else{
	  leftwards[i].push_back(Lane(i,j,lane[i][j]));
	}
      }
    }
  }
  for(int i=0;i<N;i++){
    std::reverse(leftwards[i].begin(),leftwards[i].end());
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      path[0][i][j]=0;
    }
  }
  for(int k=1;k<=K;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	path[k][i][j]=INF;
      }
    }
  }
  for(int len=1;len<=K;len++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if(i<j){
	  for(Lane lane:leftwards[j]){
	    if(lane.V>i){
	      path[len][i][j]=
		std::min(path[len][i][j],
			 lane.C+std::min(path[len-1][lane.U][lane.V],
					 path[len-1][i][lane.V]));
	    }else{
	      break;
	    }
	  }
	}else if(i>j){
	  for(Lane lane:rightwards[j]){
	    if(lane.V<i){
	      path[len][i][j]=
		std::min(path[len][i][j],
			 lane.C+std::min(path[len-1][lane.U][lane.V],
					 path[len-1][i][lane.V]));
	    }else{
	      break;
	    }
	  }
	}
	/*
	if(path[len][i][j]<INF){
	  std::cerr<<"Path["<<len<<"]["<<i<<"]["<<j<<"]="<<path[len][i][j]<<std::endl;
	}
	*/
      }
    }
  }
  int best=INF;
  for(int i=1;i<N-1;i++){
    best=std::min(best,path[K-1][0][i]);
    best=std::min(best,path[K-1][N-1][i]);
  }
  if(best<INF){
    std::cout<<best<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}