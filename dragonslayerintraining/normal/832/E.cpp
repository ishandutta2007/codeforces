#include <cstdio>
#include <cassert>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;

int N,M,Q;

int inv[5]={0,1,3,2,4};

int mat[500][500];
char str[505];

int start[500];

int query[500];

int64_t cnt=1;

void swaprows(int r1[500],int r2[500]){
  for(int i=0;i<M;i++){
    std::swap(r1[i],r2[i]);
  }
}

void addrow(int r1[500],int r2[500],int scale){
  for(int i=0;i<M;i++){
    r2[i]=(r2[i]+r1[i]*scale)%5;
  }
}

void reduce(){
  std::fill(start,start+N,-1);
  int i=0;
  for(int j=0;j<M;j++){
    for(int k=i;k<N;k++){
      if(mat[k][j]!=0){
	swaprows(mat[i],mat[k]);
	break;
      }
    }
    if(mat[i][j]==0){
      continue;
    }
    for(int k=i+1;k<N;k++){
      addrow(mat[i],mat[k],(5-mat[k][j]*inv[mat[i][j]]%5)%5);
      assert(mat[k][j]==0);
    }
    start[i++]=j;
    if(i==N){
      return;
    }
  }
  for(;N>i;N--){
    cnt=(cnt*5)%MOD;
  }
}

bool spanned(){
  int i=0;
  for(int j=0;j<M;j++){
    if(mat[i][j]){
      addrow(mat[i],query,(5-query[j]*inv[mat[i][j]]%5)%5);
      if(++i==N){
	break;
      }
    }
  }
  for(int j=0;j<M;j++){
    if(query[j]!=0){
      return false;
    }
  }
  return true;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    for(int j=0;j<M;j++){
      mat[i][j]=str[j]-'a';
    }
  }
  reduce();
  
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    scanf("%s",str);
    for(int j=0;j<M;j++){
      query[j]=str[j]-'a';
    }
    if(spanned()){
      printf("%I64d\n",cnt);
    }else{
      printf("0\n");
    }
  }
  return 0;
}