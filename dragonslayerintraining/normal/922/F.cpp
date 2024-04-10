#include <cstdio>
#include <vector>
#include <cstdlib>
#include <stdint.h>

std::vector<int> factors[300001];

std::vector<int> unused,used;

bool bs[300001];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int i=1;i<=N;i++){
    for(int k=i*2;k<=N;k+=i){
      factors[k].push_back(i);
    }
  }
  for(int i=1;i<=N;i++){
    unused.push_back(i);
  }
  for(int i=0;i<1000000;i++){
    if(K>0){
      if(unused.empty()){
	printf("No\n");
	return 0;
      }
      std::swap(unused[rand()%unused.size()],unused.back());
      int v=unused.back();
      unused.pop_back();
      used.push_back(v);
      for(int f:factors[v]){
	if(bs[f]){
	  K--;
	}
      }
      for(int k=v*2;k<=N;k+=v){
	if(bs[k]){
	  K--;
	}
      }
      bs[v]=true;
    }else if(K<0){
      if(used.empty()){
	printf("No\n");
	return 0;
      }
      std::swap(used[rand()%used.size()],used.back());
      int v=used.back();
      used.pop_back();
      unused.push_back(v);
      for(int f:factors[v]){
	if(bs[f]){
	  K++;
	}
      }
      for(int k=v*2;k<=N;k+=v){
	if(bs[k]){
	  K++;
	}
      }
      bs[v]=false;
    }else{
      break;
    }
  }
  if(K!=0){
    printf("No\n");
  }else{
    printf("Yes\n");
    printf("%d\n",used.size());
    for(int i=0;i<used.size();i++){
      if(i>0){
	printf(" ");
      }
      printf("%d",used[i]);
    }
    printf("\n");
  }
  return 0;
}