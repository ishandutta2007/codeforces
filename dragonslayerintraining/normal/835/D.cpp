#include <cstdio>
#include <algorithm>
#include <cstring>

char str[5005];
int len;

int kpal[5001][5001];

int cnt[5001];

int main(){
  scanf("%s",str);
  len=strlen(str);
  for(int i=0;i<len;i++){
    for(int j=0;(j<=i)&&(i+j<len);j++){
      if(str[i-j]!=str[i+j]){
	break;
      }
      //fprintf(stderr,"Odd (%d,%d)\n",i-j,i+j);
      kpal[i-j][(i+j)+1]=1;
    }
    for(int j=0;(j<=i)&&(i+j+1<len);j++){
      if(str[i-j]!=str[i+j+1]){
	break;
      }
      //fprintf(stderr,"Even (%d,%d)\n",i-j,i+j+1);
      kpal[i-j][(i+j+1)+1]=1;
    }
  }
  for(int l=1;l<=len;l++){
    for(int i=0;i+l<=len;i++){
      int j=i+l;
      int half=l/2;
      if(kpal[i][j]){
	kpal[i][j]=1+std::min(kpal[i][i+half],
			      kpal[j-half][j]);
	//fprintf(stderr,"(%d,%d) is a %d-palindrome\n",i,j-1,kpal[i][j]);
      }
    }
  }
  for(int i=0;i<len;i++){
    for(int j=i;j<len;j++){
      cnt[kpal[i][j+1]]++;
    }
  }
  for(int i=len;i>0;i--){
    cnt[i-1]+=cnt[i];
  }
  for(int i=1;i<=len;i++){
    if(i>1){
      printf(" ");
    }
    printf("%d",cnt[i]);
  }
  printf("\n");
  return 0;
}