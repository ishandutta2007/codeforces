#include <cstdio>
#include <queue>
#include <stdint.h>

std::priority_queue<int64_t,std::deque<int64_t>,std::greater<int64_t> > queue;
int64_t cost=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    queue.push(A);
  }
  if(queue.size()%2==0){
    int64_t x=queue.top();
    queue.pop();
    int64_t y=queue.top();
    queue.pop();
    cost+=x+y;
    queue.push(x+y);
  }
  while(queue.size()>1){
    int64_t x=queue.top();
    queue.pop();
    int64_t y=queue.top();
    queue.pop();
    int64_t z=queue.top();
    queue.pop();
    cost+=x+y+z;
    queue.push(x+y+z);
  }
  printf("%I64d\n",cost);
  return 0;
}