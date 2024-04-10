#include <cstdio>

int N;
char str1[2000005];
char str2[2000005];

int cnt[3];
int diff=0;

int main(){
  scanf("%d %s %s",&N,str1,str2);
  for(int i=0;i<N*2;i++){
    cnt[str1[i]-'0'+str2[i]-'0']++;
    diff+=(str1[i]-'0');
    diff-=(str2[i]-'0');
  }
  if(cnt[1]%2==1){
    diff++;
  }else if(cnt[2]%2==1){
    diff+=2;
  }
  if(diff>0){
    printf("First\n");
  }else if(diff<0){
    printf("Second\n");
  }else{
    printf("Draw\n");
  }
  return 0;
}