#include <cstdio>
#include <vector>

bool compare(int i,int j){
  printf("? %d %d\n",i,j);
  fflush(stdout);
  char res;
  scanf(" %c",&res);
  return res=='<';
}

void answer(int i,int j){
  printf("! %d %d\n",i,j);
  fflush(stdout);
}

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<int> min,max;
  for(int i=1;i<=N;i+=2){
    if(i+1<=N){
      if(compare(i,i+1)){
	min.push_back(i);
	max.push_back(i+1);
      }else{
	min.push_back(i+1);
	max.push_back(i);
      }
    }else{
      min.push_back(i);
      max.push_back(i);
    }
  }
  while(min.size()>1){
    int a=min.back();
    min.pop_back();
    int b=min.back();
    min.pop_back();
    if(compare(a,b)){
      min.push_back(a);
    }else{
      min.push_back(b);
    }
  }
  while(max.size()>1){
    int a=max.back();
    max.pop_back();
    int b=max.back();
    max.pop_back();
    if(compare(a,b)){
      max.push_back(b);
    }else{
      max.push_back(a);
    }
  }
  answer(min[0],max[0]);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}