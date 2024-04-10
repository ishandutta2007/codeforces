#include <cstdio>
#include <vector>

std::vector<int> ps;

void add_cycle(int len){
  int first=ps.size();
  for(int i=1;i<len;i++){
    ps.push_back(first+i);
  }
  ps.push_back(first);
}

int main(){
  int N,A,B;
  scanf("%d %d %d",&N,&A,&B);
  for(int a=0;a*A<=N;a++){
    if((N-a*A)%B!=0) continue;
    int b=(N-a*A)/B;
    while(a-->0){
      add_cycle(A);
    }
    while(b-->0){
      add_cycle(B);
    }
    for(int i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",ps[i]+1);
    }
    printf("\n");
    return 0;
  }
  printf("-1\n");
  return 0;
}