#include <cstdio>
#include <map>
#include <array>
#include <cmath>
#include <vector>

const int64_t MOD=1e9+7;

std::map<int64_t,std::array<int64_t,3> > obstacles;

struct Matrix{
  int64_t mat[3][3];
  Matrix(){
    for(int64_t i=0;i<3;i++){
      for(int64_t j=0;j<3;j++){
	mat[i][j]=0;
      }
    }
  }
  Matrix(std::array<int64_t,3> block){
    for(int64_t i=0;i<3;i++){
      for(int64_t j=0;j<3;j++){
	mat[i][j]=(std::abs(i-j)<=1)&&!block[i];
      }
    }
  }
  int64_t& operator()(int64_t i,int64_t j){
    return mat[i][j];
  }
  int64_t operator()(int64_t i,int64_t j)const{
    return mat[i][j];
  }
  struct Matrix operator*(struct Matrix other)const{
    struct Matrix ret;
    for(int64_t i=0;i<3;i++){
      for(int64_t j=0;j<3;j++){
	for(int64_t k=0;k<3;k++){
	  ret(i,j)+=(*this)(i,k)*other(k,j);
	  ret(i,j)%=MOD;
	}
      }
    }
    return ret;
  }
  void dump(){
    for(int64_t i=0;i<3;i++){
      for(int64_t j=0;j<3;j++){
	if(j) printf(" ");
	printf("%I64d",mat[i][j]);
      }
      printf("\n");
    }
  }
};

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=0;i<N;i++){
    int64_t A,L,R;
    scanf("%I64d %I64d %I64d",&A,&L,&R);
    A--;
    L--;
    obstacles[L][A]++;
    obstacles[R][A]--;
  }
  obstacles[0];
  obstacles[M-1];
  std::vector<std::pair<int64_t,std::array<int64_t,3> > > changes(obstacles.begin(),obstacles.end());
  std::array<int64_t,3> blocked({0,0,0});
  struct Matrix ac;
  for(int64_t i=0;i<3;i++){
    ac(i,i)=1;
  }
  for(int64_t i=0;i<changes.size()-1;i++){
    for(int64_t r=0;r<3;r++){
      blocked[r]+=changes[i].second[r];
    }
    /*
    print64_tf("%I64d-%I64d: \n",changes[i].first,changes[i+1].first);
    for(int64_t r=0;r<3;r++){
      print64_tf("BLOCK[%I64d]=%I64d\n",r,blocked[r]);
    }
    */
    struct Matrix base(blocked);
    //base.dump();
    for(int64_t exp=changes[i+1].first-changes[i].first;exp>0;exp>>=1){
      if(exp&1) ac=ac*base;
      base=base*base;
    }
  }
  printf("%I64d\n",ac(1,1));
  return 0;
}