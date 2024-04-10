#include <cstdio>
#include <vector>

int as[101];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::vector<int> choose({1});
  int maj=as[0];
  int total=as[0];
  for(int i=1;i<N;i++){
    if(as[0]>=2*as[i]){
      maj+=as[i];
      choose.push_back(i+1);
    }
    total+=as[i];
  }
  if(2*maj>total){
    printf("%d\n",(int)choose.size());
    for(int i=0;i<choose.size();i++){
      if(i) printf(" ");
      printf("%d",choose[i]);
    }
    printf("\n");
  }else{
    printf("0\n");
  }
  return 0;
}