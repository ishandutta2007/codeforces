#include <iostream>
#include <vector>
#include <stdint.h>

const int64_t MOD=1000000007;

struct ccounts{
  int64_t types[3][3];
  ccounts(){
    for(int64_t i=0;i<3;i++){
      for(int64_t j=0;j<3;j++){
	types[i][j]=0;
      }
    }
  }
};

struct ccounts concat(struct ccounts a,struct ccounts b){
  struct ccounts ret;
  for(int64_t i=0;i<3;i++){
    for(int64_t j=0;j<3;j++){
      for(int64_t k=0;k<3;k++){
	for(int64_t l=0;l<3;l++){
	  if((k==0)||(l==0)||(l!=k)){
	    ret.types[i][j]+=a.types[i][k]*b.types[l][j];
	    ret.types[i][j]%=MOD;
	  }
	}
      }
    }
  }
  return ret;
}

struct ccounts surround(struct ccounts a){
  struct ccounts ret;
  for(int64_t i=0;i<3;i++){
    for(int64_t j=0;j<3;j++){
      if((i==0)^(j==0)){
	for(int64_t k=0;k<3;k++){
	  for(int64_t l=0;l<3;l++){
	    if(((i==0)||(k==0)||(i!=k))&&
	       ((j==0)||(l==0)||(j!=l))){
	      ret.types[i][j]+=a.types[k][l];
	      ret.types[i][j]%=MOD;
	    }
	  }
	}
      }
    }
  }
  return ret;
}

struct ccounts empty(){
  struct ccounts ret;
  ret.types[1][0]=1;
  ret.types[2][0]=1;
  ret.types[0][1]=1;
  ret.types[0][2]=1;
  return ret;
}

struct ccounts parse(){
  std::vector<std::vector<struct ccounts> > stk;
  stk.push_back(std::vector<struct ccounts>());
  while(true){
    switch(std::cin.get()){
    case '(':
      stk.push_back(std::vector<struct ccounts>());
      break;
    case ')':{
      struct ccounts comb;
      if(stk.back().empty()){
	comb=empty();
      }else{
	while(stk.back().size()>1){
	  struct ccounts end=stk.back().back();
	  stk.back().pop_back();
	  stk.back().back()=concat(stk.back().back(),end);
	}
	comb=surround(stk.back().back());
      }
      stk.pop_back();
      stk.back().push_back(comb);
      break;
    }
    default:
      while(stk.back().size()>1){
	struct ccounts end=stk.back().back();
	stk.back().pop_back();
	stk.back().back()=concat(stk.back().back(),end);
      }
      return stk.back().back();
    }
  }
}

int main(){
  struct ccounts counts=parse();
  int64_t cnt=0;
  for(int64_t i=0;i<3;i++){
    for(int64_t j=0;j<3;j++){
      cnt+=counts.types[i][j];
      cnt%=MOD;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}