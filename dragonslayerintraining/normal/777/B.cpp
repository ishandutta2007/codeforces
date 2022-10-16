#include <cstdio>
#include <algorithm>

int as[10];
int bs[10];

char str[100005];

int main(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    as[str[i]-'0']++;
  }
  scanf("%s",str);
  for(int i=0;i<N;i++){
    bs[str[i]-'0']++;
  }
  {
    int small=0;
    int score=0;
    for(int i=0;i<10;i++){
      small+=as[i];
      score+=std::min(small,bs[i]);
      small-=std::min(small,bs[i]);
    }
    printf("%d\n",N-score);
  }
  {
    int small=0;
    int score=0;
    for(int i=0;i<10;i++){
      score+=std::min(small,bs[i]);
      small-=std::min(small,bs[i]);
      small+=as[i];
    }
    printf("%d\n",score);
  }
  return 0;
}