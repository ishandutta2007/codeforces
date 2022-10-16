#include <cstdio>
#include <map>

int N;
char str[100005];
int prefix[100005];

std::map<int,int> first;

int main(){
  scanf("%d",&N);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    prefix[i+1]=prefix[i]+((str[i]=='1')?1:-1);
  }
  int best=0;
  for(int i=0;i<=N;i++){
    if(first.count(prefix[i])){
      best=std::max(best,i-first[prefix[i]]);
    }else{
      first[prefix[i]]=i;
    }
  }
  printf("%d\n",best);
  return 0;
}