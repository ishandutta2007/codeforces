#include <cstdio>
#include <vector>

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<int> stk;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A==1){
      stk.push_back(A);
    }else{
      while(stk.back()+1!=A){
	stk.pop_back();
      }
      stk.back()++;
    }
    for(int k=0;k<stk.size();k++){
      if(k>0) printf(".");
      printf("%d",stk[k]);
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}