#include <iostream>

int as[100001];

int main(){
  int H;
  std::cin>>H;
  std::cin>>as[0];
  for(int i=1;i<=H;i++){
    std::cin>>as[i];
  }
  for(int i=0;i<H;i++){
    if((as[i]>1)&&(as[i+1]>1)){
      std::cout<<"ambiguous"<<std::endl;
      //first tree
      {
	std::cout<<0;
	int rep=1;
	for(int j=1;j<=H;j++){
	  for(int k=0;k<as[j];k++){
	    std::cout<<" "<<rep;
	  }
	  rep+=as[j-1];
	}
	std::cout<<std::endl;
      }
      //second tree
      {
	std::cout<<0;
	int rep=1;
	for(int j=1;j<=H;j++){
	  for(int k=0;k<as[j];k++){
	    if((j==i+1)&&(k>0)){
	      std::cout<<" "<<(rep+1);
	    }else{
	      std::cout<<" "<<rep;
	    }
	  }
	  rep+=as[j-1];
	}
	std::cout<<std::endl;
      }
      return 0;
    }
  }
  std::cout<<"perfect"<<std::endl;
  return 0;
}