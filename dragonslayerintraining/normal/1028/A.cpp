#include <cstdio>

char str[128];

int main(){
  int R,C;
  scanf("%d %d",&R,&C);
  int rsum=0,csum=0,cnt=0;
  for(int r=0;r<R;r++){
    scanf("%s",str);
    for(int c=0;c<C;c++){
      if(str[c]=='B'){
	rsum+=r+1;
	csum+=c+1;
	cnt++;
      }
    }
  }
  printf("%d %d\n",rsum/cnt,csum/cnt);
  return 0;
}