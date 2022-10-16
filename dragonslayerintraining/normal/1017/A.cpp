#include <cstdio>
#include <algorithm>

std::pair<int,int> students[1001];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    students[i].first=-(A+B+C+D);
    students[i].second=i;
  }
  std::sort(students,students+N);
  for(int i=0;i<N;i++){
    if(students[i].second==0){
      printf("%d\n",i+1);
      return 0;
    }
  }
  return 0;
}