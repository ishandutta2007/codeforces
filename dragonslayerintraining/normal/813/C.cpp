#include <iostream>
#include <vector>

std::vector<int> edges[200000];

int avis[200000];
int bvis[200000];

int main(){
  int N,X;
  std::cin>>N>>X;
  X--;
  for(int i=1;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  std::vector<std::pair<int,int> > alice,bob;
  alice.emplace_back(0,0);
  bob.emplace_back(X,X);
  for(int turn=1;turn<=N;turn++){
    {
      std::vector<std::pair<int,int> > tmp;
      for(std::pair<int,int> pair:bob){
	int node=pair.first;
	if((avis[node]==0)&&(bvis[node]==0)&&(avis[pair.second]==0)){
	  bvis[node]=turn;
	  for(int child:edges[node]){
	    tmp.emplace_back(child,node);
	  }
	}
      }
      std::swap(tmp,bob);
    }
    {
      std::vector<std::pair<int,int> > tmp;
      for(std::pair<int,int> pair:alice){
	int node=pair.first;
	if(avis[node]==0){
	  avis[node]=turn;
	  for(int child:edges[node]){
	    tmp.emplace_back(child,node);
	  }
	}
      }
      std::swap(tmp,alice);
    }
  }
  int best=0;
  for(int i=0;i<N;i++){
    if(bvis[i]>0){
      best=std::max(best,avis[i]-1);
    }
  }
  std::cout<<best*2<<std::endl;
  return 0;
}