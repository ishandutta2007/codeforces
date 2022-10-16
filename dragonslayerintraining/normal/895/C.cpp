#include <cstdio>
#include <vector>
#include <stdint.h>
#include <algorithm>

const int64_t MOD=1e9+7;

int N;

bool composite[71];
int64_t mask[71];

void init_masks(){
  int last=0;
  for(int i=2;i<=70;i++){
    if(!composite[i]){
      for(int j=i;j<=70;j*=i){
	for(int k=j;k<=70;k+=j){
	  mask[k]^=(1LL<<last);
	  composite[k]=true;
	}
      }
      last++;
    }
    //printf("%d: %I64d\n",i,mask[i]);
  }
}

std::vector<int64_t> basis;

int main(){
  init_masks();
  int64_t cnt=1;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    A=mask[A];
    //printf("ORIGINAL: %I64d\n",A);
    for(int b:basis){
      if((A^b)<A){
	A^=b;
      }
    }
    if(A){
      //printf("BASIS: %I64d\n",A);
      basis.push_back(A);
      std::sort(basis.begin(),basis.end());
      std::reverse(basis.begin(),basis.end());
    }else{
      cnt=cnt*2%MOD;
    }
  }
  printf("%I64d\n",cnt-1);
  return 0;
}