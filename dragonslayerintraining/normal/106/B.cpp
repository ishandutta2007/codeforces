#include <iostream>

struct claptop{
  int A,B,C;
  int cost;
  bool outdated;
  claptop():outdated(false){
  }
}laptops[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>laptops[i].A>>laptops[i].B>>laptops[i].C>>laptops[i].cost;
  }
  for(int i=0;i<N;i++){
    struct claptop&l1=laptops[i];
    for(int j=0;j<N;j++){
      struct claptop& l2=laptops[j];
      if((l1.A<l2.A)&&(l1.B<l2.B)&&(l1.C<l2.C)){
	l1.outdated=true;
	std::cerr<<i<<" is outdated"<<std::endl;
	break;
      }
    }
  }
  int besti=0;
  int best=1e9;
  for(int i=0;i<N;i++){
    if(!laptops[i].outdated){
      if(laptops[i].cost<best){
	besti=i+1;
	best=laptops[i].cost;
      }
    }
  }
  std::cout<<besti<<std::endl;
  return 0;
}