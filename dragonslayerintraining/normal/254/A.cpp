#include <cstdio>
#include <vector>

std::vector<int> as[5000];

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int N;
  scanf("%d",&N);
  for(int i=0;i<N*2;i++){
    int A;
    scanf("%d",&A);
    A--;
    as[A].push_back(i);
  }
  for(int i=0;i<5000;i++){
    if(as[i].size()%2==1){
      printf("-1\n");
      return 0;
    }
  }
  for(int i=0;i<5000;i++){
    for(int j=0;j<as[i].size();j+=2){
      printf("%d %d\n",as[i][j]+1,as[i][j+1]+1);
    }
  }
  return 0;
}