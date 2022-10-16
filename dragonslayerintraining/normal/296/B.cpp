#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

int N;

char str1[100005],str2[100005];

int64_t any=1,ge=1,le=1,eq=1;

int main(){
  scanf("%d %s %s",&N,str1,str2);
  for(int i=0;i<N;i++){
    if((str1[i]=='?')&&(str2[i]=='?')){
      any=(any*100)%MOD;
      ge=(ge*55)%MOD;
      le=(le*55)%MOD;
      eq=(eq*10)%MOD;
    }else if(str1[i]=='?'){
      any=(any*10)%MOD;
      ge=(ge*('9'-str2[i]+1))%MOD;
      le=(le*(str2[i]-'0'+1))%MOD;
    }else if(str2[i]=='?'){
      any=(any*10)%MOD;
      ge=(ge*(str1[i]-'0'+1))%MOD;
      le=(le*('9'-str1[i]+1))%MOD;
    }else if(str1[i]>str2[i]){
      le=eq=0;
    }else if(str1[i]<str2[i]){
      ge=eq=0;
    }
  }
  printf("%ld\n",(MOD*2+any-ge-le+eq)%MOD);
  return 0;
}