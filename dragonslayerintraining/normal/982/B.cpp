#include <cstdio>
#include <set>

char str[400005];

int main(){
  std::set<std::pair<int,int> > two,one;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int W;
    scanf("%d",&W);
    two.emplace(W,i+1);
  }
  scanf("%s",str);
  for(int i=0;str[i];i++){
    if(i) printf(" ");
    switch(str[i]){
    case '0':{
      printf("%d",two.begin()->second);
      one.insert(*two.begin());
      two.erase(two.begin());
      break;
    }
    case '1':{
      printf("%d",one.rbegin()->second);
      one.erase(*one.rbegin());
      break;
    }
    }
  }
  printf("\n");
  return 0;
}