#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> left,right;

int main(){
  int N,M,C;
  scanf("%d %d %d",&N,&M,&C);
  while(left.size()+right.size()<N){
    int P;
    scanf("%d",&P);
    if(P>C/2){
      //insert into right
      auto it=std::upper_bound(right.begin(),right.end(),-P);
      printf("%d\n",N-int(it-right.begin()));
      if(it==right.end()){
	right.push_back(-P);
      }else{
	*it=-P;
      }
    }else{
      //insert into left
      auto it=std::upper_bound(left.begin(),left.end(),P);
      printf("%d\n",int(it-left.begin())+1);
      if(it==left.end()){
	left.push_back(P);
      }else{
	*it=P;
      }
    }
    fflush(stdout);
  }
  return 0;
}