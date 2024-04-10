#include <cstdio>

bool used[3000000];
int maxfactor[3000000];
int as[100000];

bool isbad(int x){
  for(;x>1;x/=maxfactor[x]){
    if(used[maxfactor[x]]){
      return true;
    }
  }
  return false;
}

void mark(int x){
  for(;x>1;x/=maxfactor[x]){
    used[maxfactor[x]]=true;
  }
}

int main(){
  for(int i=2;i<3000000;i++){
    if(maxfactor[i]==0){
      for(int k=i;k<3000000;k+=i){
	maxfactor[k]=i;
      }
    }
    //printf("maxfactor[%d]=%d\n",i,maxfactor[i]);
  }
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int i;
  for(i=0;i<N;i++){
    if(isbad(as[i])){
      while(isbad(as[i])){
	//printf("%d BAD\n",as[i]);
	as[i]++;
      }
      mark(as[i]);
      i++;
      break;
    }
    mark(as[i]);
  }
  int last=2;
  for(;i<N;i++){
    while(isbad(last)){
      last++;
    }
    mark(last);
    as[i]=last;
  }
  for(int i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}