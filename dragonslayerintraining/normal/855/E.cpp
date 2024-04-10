#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>

uint64_t cnt[11][70][1<<10];
uint64_t solo[11][70];

int64_t query(int64_t B,int64_t X){
  std::vector<int> digits;
  for(;X;X/=B){
    digits.push_back(X%B);
  }
  std::reverse(digits.begin(),digits.end());
  /*
  for(int i=0;i<digits.size();i++){
    printf("%d",digits[i]);
  }
  printf("\n");
  */
  int prefix=0;
  int64_t ans=solo[B][digits.size()-1];
  for(int i=0;i<digits.size();i++){
    for(int d=(i==0);d<digits[i];d++){
      ans+=cnt[B][digits.size()-i-1][prefix^(1<<d)];
      //printf("DIGIT=%d PREFIX-MASK %d, REMAINING=%d, CNT=%I64d\n",d,prefix,(int)digits.size()-i-1,cnt[B][digits.size()-i-1][prefix^(1<<d)]);
    }
    //printf("ADD DIGIT %d\n",digits[i]);
    prefix^=(1<<digits[i]);
  }
  return ans;
}

int main(){
  for(int b=2;b<=10;b++){
    cnt[b][0][0]=1;
    for(int l=1;l<70;l++){
      for(int mask=0;mask<(1<<b);mask++){
	for(int d=0;d<b;d++){
	  cnt[b][l][mask]+=cnt[b][l-1][mask^(1<<d)];
	}
	//printf("CNT B=%d: mask=%d l=%d\t %I64d\n",b,mask,l,cnt[b][l][mask]);
      }
      solo[b][l]=cnt[b][l][0]-cnt[b][l-1][1<<0]+solo[b][l-1];
      //printf("SOLO B=%d L=%d: %lu\n",b,l,solo[b][l]);
    }
  }
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int64_t B,L,R;
    scanf("%I64d %I64d %I64d",&B,&L,&R);
    printf("%I64d\n",query(B,R+1)-query(B,L));
  }
  return 0;
}