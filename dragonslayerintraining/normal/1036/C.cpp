#include <cstdio>
#include <vector>
#include <algorithm>

int64_t dp[20][5];//dp[len][num nonzero]

int64_t query(int64_t X){
  std::vector<int> digits;
  for(;X;X/=10){
    digits.push_back(X%10);
  }
  std::reverse(digits.begin(),digits.end());
  int64_t nonzero=0;
  int64_t ans=0;
  for(int64_t i=0;i<digits.size();i++){
    if(digits[i]==0) continue;
    ans+=dp[digits.size()-i-1][3-nonzero];
    if(nonzero<=2){
      ans+=(digits[i]-1)*dp[digits.size()-i-1][2-nonzero];
    }
    if(++nonzero>3) break;
  }
  return ans;
}

int main(){
  dp[0][0]=1;
  for(int64_t l=0;l<19;l++){
    for(int64_t z=0;z<=3;z++){
      dp[l+1][z]+=dp[l][z];
      dp[l+1][z+1]+=dp[l][z]*9;
    }
  }
  for(int64_t l=0;l<19;l++){
    for(int64_t z=0;z<3;z++){
      dp[l][z+1]+=dp[l][z];
    }
    /*
    for(int64_t z=0;z<5;z++){
      printf("dp[%I64d][%I64d]=%I64d\n",l,z,dp[l][z]);
    }
    */
    dp[l][4]=0;
  }
  int64_t T;
  scanf("%I64d",&T);
  while(T-->0){
    int64_t L,R;
    scanf("%I64d %I64d",&L,&R);
    printf("%I64d\n",query(R+1)-query(L));
  }
  return 0;
}