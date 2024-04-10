#include <cstdio>

int home[100000],away[100000];
int color_home[100001];
int color_away[100001];
int cnt_home[100001];
int cnt_away[100001];

int main(){
  int N; 
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&home[i],&away[i]);
    color_home[home[i]]++;
    color_away[away[i]]++;
  }
  for(int i=0;i<N;i++){
    cnt_home[i]+=N-1;
    cnt_home[i]+=color_home[away[i]];
    cnt_away[i]+=N-1-color_home[away[i]];
    printf("%d %d\n",cnt_home[i],cnt_away[i]);
  }
  return 0;
}