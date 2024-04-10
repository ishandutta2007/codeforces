#include <cstdio>
#include <vector>

std::vector<int> moves;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=2;i<=N;i+=2){
    moves.push_back(i);
  }
  for(int i=1;i<=N;i+=2){
    moves.push_back(i);
  }
  for(int i=2;i<=N;i+=2){
    moves.push_back(i);
  }
  printf("%d\n",(int)moves.size());
  for(int i=0;i<moves.size();i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",moves[i]);
  }
  printf("\n");
  return 0;
}