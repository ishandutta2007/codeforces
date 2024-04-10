#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

int as[1000005];
int N;

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  std::vector<bool> vis(N);
  int cnt=0;
  for(int i=0;i<N;i++){
    if(!vis[i]){
      for(int j=i;!vis[j];j=as[j]){
	vis[j]=true;
      }
      cnt++;
    }
  }
  if(cnt%2==0){
    printf("Petr\n");
  }else{
    printf("Um_nik\n");
  }
  return 0;
}