#include <cstdio>
#include <cassert>
#include <algorithm>
#include <stdint.h>

const bool debug=false;
int64_t P;

void setadd(int64_t& x,int64_t y){
  x=(x+y)%P;
}
void setmul(int64_t& x,int64_t y){
  x=(x*y)%P;
}

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp;exp>>=1){
    if(exp&1) setmul(ac,base);
    setmul(base,base);
  }
  return ac;
}

int64_t inverse(int64_t x){
  return modpow(x,P-2);
}

const int REG_ONE=4999;
const int REG_ZERO=5000;

int reg[5001]={0,2,3};

int64_t mat[11][12];
int64_t poly[11][11];//[exp][deg]
int64_t D;

void instr_add(int64_t a,int64_t b,int64_t c){
  assert(a>=1&&a<=5000);
  assert(b>=1&&b<=5000);
  assert(c>=1&&c<=5000);
  printf("+ %I64d %I64d %I64d\n",a,b,c);
  reg[c]=(reg[a]+reg[b])%P;
}

void instr_exp(int64_t a,int64_t b){
  assert(a>=1&&a<=5000);
  assert(b>=1&&b<=5000);
  printf("^ %I64d %I64d\n",a,b);
  reg[b]=modpow(reg[a],D);
}

void instr_ret(int64_t a){
  assert(a>=1&&a<=5000);
  printf("f %I64d\n",a);
  if(debug) printf("RET %d\n",reg[a]);
}

void instr_copy(int a,int b){
  instr_add(a,REG_ZERO,b);
}

void pow_poly(int64_t a){
  for(int64_t i=0;i<=D;i++){
    for(int64_t j=0;j<=D;j++){
      poly[i][j]=0;
    }
  }
  poly[0][0]=1;
  for(int64_t i=0;i<D;i++){
    for(int64_t j=0;j<D;j++){
      setadd(poly[i+1][j],a*poly[i][j]);
      setadd(poly[i+1][j+1],poly[i][j]);
    }
  }
  if(debug){
    printf("(x+%I64d)^%I64d=",a,D);
    for(int64_t i=0;i<=D;i++){
      printf("%I64dx^%I64d+",poly[D][i],i);
    }
    printf("\n");
  }
}

void dump_mat(){
  return;
  if(!debug) return;
  for(int64_t i=0;i<=D;i++){
    for(int64_t j=0;j<=D+1;j++){
      printf("%I64d ",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void dump_regs(){
  if(!debug) return;
  for(int i=1;i<=5000;i++){
    if(reg[i]!=1) printf("REG[%d]=%d\n",i,reg[i]);
  }
}

void instr_square(int a){
  if(debug) printf("half square %d\n",a);
  const int TMP=2000;
  const int RES=TMP+D+1;
  instr_copy(a,TMP);
  for(int i=1;i<=D;i++){
    instr_add(TMP+i-1,REG_ONE,TMP+i);
  }
  for(int i=0;i<=D;i++){
    instr_exp(TMP+i,TMP+i);
  }
  instr_copy(REG_ZERO,RES);
  for(int k=30-1;k>=0;k--){
    instr_add(RES,RES,RES);
    for(int i=0;i<=D;i++){
      if(mat[i][D+1]&(1LL<<k)){
	instr_add(TMP+i,RES,RES);
      }
    }
  }
  instr_copy(RES,a);
}

int main(){
  std::fill(reg+3,reg+5001,1);
  scanf("%I64d %I64d",&D,&P);
  for(int64_t i=0;i<=D;i++){
    pow_poly(i);
    for(int64_t j=0;j<=D;j++){
      mat[j][i]=poly[D][j];
    }
  }
  mat[2][D+1]=inverse(2);
  dump_mat();
  for(int64_t i=0;i<=D;i++){
    for(int64_t j=i;j<=D;j++){
      if(mat[j][i]){
	for(int64_t k=0;k<=D+1;k++){
	  std::swap(mat[i][k],mat[j][k]);
	}
	break;
      }
    }
    assert(mat[i][i]);
    dump_mat();
    int64_t scale=inverse(mat[i][i]);
    for(int64_t k=0;k<=D+1;k++){
      setmul(mat[i][k],scale);
    }
    dump_mat();
    for(int64_t j=i+1;j<=D;j++){
      int64_t scale=P-mat[j][i];
      for(int64_t k=0;k<=D+1;k++){
	setadd(mat[j][k],scale*mat[i][k]);
      }
    }
    dump_mat();
  }
  for(int64_t i=D;i>=0;i--){
    for(int64_t j=0;j<i;j++){
      int64_t scale=P-mat[j][i];
      for(int64_t k=0;k<=D+1;k++){
	setadd(mat[j][k],scale*mat[i][k]);
      }
    }
    dump_mat();
  }
  if(debug){
    for(int64_t i=0;i<=D;i++){
      printf("%I64d(x+%I64d)^%I64d\n",mat[i][D+1],i,D);
    }
  }
  for(int k=0;k<30;k++){
    if((P-1)&(1LL<<k)){
      instr_add(4998,REG_ZERO,REG_ZERO);
    }
    instr_add(4998,4998,4998);
  }
  instr_add(1,2,3);
  dump_regs();
  instr_square(1);
  dump_regs();
  instr_square(2);
  dump_regs();
  instr_square(3);
  dump_regs();
  instr_add(1,2,2);
  dump_regs();
  for(int k=0;k<30;k++){
    if((P-1)&(1LL<<k)){
      instr_add(2,3,3);
    }
    instr_add(2,2,2);
  }
  instr_ret(3);
  return 0;
}