#include <cstdio>

int K;
char num[100005];
int digit[10];

int main(){
  scanf("%d %s",&K,num);
  for(int i=0;num[i];i++){
    digit[num[i]-'0']++;
    K-=(num[i]-'0');
  }
  int delta=0;
  if(K<=0){
    printf("%d\n",delta);
    return 0;
  }
  for(int i=0;i<10;i++){
    for(;digit[i]>0;digit[i]--){
      delta++;
      K-=(9-i);
      if(K<=0){
	printf("%d\n",delta);
	return 0;
      }
    }
  }
  return 0;
}