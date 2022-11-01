#include<bits/stdc++.h>

using namespace std;

int n,t1;
int cnt = 0;
int ans[1010];
bool used[1010];
char ch;

int main(int argc, char const *argv[]) {
  /* code */
  scanf("%d%c",&t1,&ch);
  while(ch==','){
    used[t1] = true;
    scanf("%d%c",&t1,&ch);
  }
  used[t1] = true;
  for (size_t i = 0; i <=1000; i++) {
    /* code */
    if(used[i]==true){
      for (size_t j = i; used[j] ; j++) {
        /* code */
        ans[i] = j;
        used[j] = false;
      }
    }
  }
  cnt = 0;
  for (size_t i = 1; i <=1000; i++) {
    /* code */
    if(ans[i]>=1){
      cnt++;
      if(cnt!=1)printf(",");
      if(ans[i] == i){
        printf("%d", i);
      }
      else
      {
        printf("%d-%d", i,ans[i]);
      }
    }
  }
  std::cout << '\n';
  return 0;
}