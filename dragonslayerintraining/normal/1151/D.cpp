#include <cstdio>
#include <algorithm>
#include <stdint.h>

struct Student{
  int a,b;
  void read(){
    scanf("%d %d",&a,&b);
  }
  bool operator<(struct Student other)const{
    return a-b>other.a-other.b;
  }
}students[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    students[i].read();
  }
  std::sort(students,students+N);
  int64_t bad=0;
  for(int64_t i=0;i<N;i++){
    bad+=students[i].a*i+students[i].b*(N-i-1);
  }
  printf("%I64d\n",bad);
  return 0;
}