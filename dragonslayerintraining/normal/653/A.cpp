#include <cstdio>
#include <map>

std::map<int,int> good;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    good[A]|=1;
    good[A-1]|=2;
    good[A+1]|=4;
  }
  for(auto it:good){
    if(it.second==7){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}