#include <cstdio>
#include <string>

int main(){
  int K;
  scanf("%d",&K);
  if(K==0){
    printf("a\n");
    return 0;
  }
  std::string res;
  int run=0;
  char c='a';
  while(K>0){
    if(K<run){
      run=0;
      c++;
    }
    K-=run;
    res+=c;
    run++;
  }
  printf("%s\n",res.c_str());
  return 0;
}