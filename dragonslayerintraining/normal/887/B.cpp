#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

std::set<int> make;

int cube[3][6];
int index[4]={0,0,0,0};

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<6;j++){
      scanf("%d",&cube[i][j]);
    }
  }
  while(index[N]==0){
    std::vector<int> arrange;
    for(int i=0;i<N;i++){
      arrange.push_back(cube[i][index[i]]);
    }
    std::sort(arrange.begin(),arrange.end());
    do{
      int num=0;
      for(int i=0;i<N;i++){
	num=num*10+arrange[i];
	make.insert(num);
      }
    }while(std::next_permutation(arrange.begin(),arrange.end()));
    {
      int i;
      for(i=0;index[i]==5;i++){
	index[i]=0;
      }
      index[i]++;
    }
  }
  int X;
  for(X=1;make.count(X);X++);
  printf("%d\n",X-1);
  return 0;
  
}