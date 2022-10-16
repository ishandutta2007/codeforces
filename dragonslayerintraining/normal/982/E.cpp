#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <stdint.h>

std::pair<int64_t,int64_t> corner[2][2];

void answer(int64_t i,int64_t j){
  i%=2;
  j%=2;
  printf("%I64d %I64d\n",corner[i][j].first,corner[i][j].second);
  exit(0);
}

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

void eea(int64_t a,int64_t& x,int64_t b,int64_t& y,int64_t c){
  if(a==0){
    if(std::abs(c)%std::abs(b)!=0){
      printf("-1\n");
      exit(0);
    }else{
      x=0,y=c/b;
    }
  }else{
    eea(b%a,y,a,x,c);
    x-=(b/a)*y;
  }
  //printf("%I64d*%I64d+%I64d*%I64d=%I64d\n",a,x,b,y,c);
}


int main(){
  int64_t N,M,X,Y,VX,VY;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&N,&M,&X,&Y,&VX,&VY);
  corner[0][0]=std::make_pair(0,0);
  corner[1][0]=std::make_pair(N,0);
  corner[0][1]=std::make_pair(0,M);
  corner[1][1]=std::make_pair(N,M);
  //canonicalize
  if(VX<0){
    X=N-X;
    VX=-VX;
    std::swap(corner[0][0],corner[1][0]);
    std::swap(corner[0][1],corner[1][1]);
  }
  if(VY<0){
    Y=M-Y;
    VY=-VY;
    std::swap(corner[0][0],corner[0][1]);
    std::swap(corner[1][0],corner[1][1]);
  }
  if(VX==0){
    std::swap(VX,VY);
    std::swap(X,Y);
    std::swap(N,M);
    std::swap(corner[0][1],corner[1][0]);
  }
  
  if(VY==0){
    //horizontal
    if(Y==0){
      answer(1,0);
    }else if(Y==M){
      answer(1,1);
    }else{
      printf("-1\n");
      return 0;
    }
  }else{
    //diagonal
    int64_t s,t;
    eea(N,s,M,t,X-Y);
    if(s<0) s=(M-(-s)%M)%M; else s%=M;
    int64_t z=N*s-X;
    int64_t MOD=N*M/gcd(N,M);
    if(z<0) z=(MOD-(-z)%MOD)%MOD; else z%=MOD;
    if(z==0) z=MOD;
    answer((X+z)/N,(Y+z)/M);
  }
  return 0;
}