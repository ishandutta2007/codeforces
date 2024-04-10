#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

int as[1000];

char grid[1000][1000];
int offset[1000];
bool split[1000];

int main(){
  int N;
  scanf("%d",&N);
  int op=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    op=std::max(op,as[i]+1);
  }
  for(int i=0;i<N;i++){
    int j=std::find(split,split+op,false)-split;
    if(j>0) j--;
    if(j==N) break;
    int k=std::find(split+j+1,split+op,true)-split;
    if(as[i]<k-j){
      offset[i]=j;
    }else{
      offset[i]=j+1;
    }
    //fprintf(stderr,"j=%d k=%d offset[%d]=%d\n",j,k,i,offset[i]);
    split[offset[i]]=true;
    split[(offset[i]+as[i])%op]=true;
    //fprintf(stderr,"mark %d\n",offset[i]);
    //fprintf(stderr,"mark %d\n",(offset[i]+as[i])%op);
  }
  assert(std::find(split,split+op,false)==split+op);
  printf("%d\n",op);
  for(int j=0;j<op;j++){
    for(int i=0;i<N;i++){
      if(((j-offset[i])%op+op)%op<as[i]){
	printf("1");
      }else{
	printf("0");
      }
    }
    printf("\n");
  }
}