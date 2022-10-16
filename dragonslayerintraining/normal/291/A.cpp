#include <cstdio>
#include <map>


std::map<int,int> cnt;

int N;

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A!=0){
      if(++cnt[A]>2){
	printf("-1\n");
	return 0;
      }
    }
  }
  int total=0;
  for(auto pair:cnt){
    total+=(pair.second==2);
  }
  printf("%d\n",total);
  return 0;
}