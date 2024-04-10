#include <cstdio>

char str1[1005],str2[1005];
int cnt1,cnt2;

int main(){
  scanf("%s %s",str1,str2);
  for(int i=0;str1[i];i++){
    cnt1+=(str1[i]=='1');
  }
  for(int i=0;str2[i];i++){
    cnt2+=(str2[i]=='1');
  }
  if(cnt2<=(cnt1+cnt1%2)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}