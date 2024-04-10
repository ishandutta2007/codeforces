#include <cstdio>
#include <queue>
#include <vector>
#include <stdint.h>

bool vis[400005];
int64_t fs[400005];

std::priority_queue<int,std::vector<int>,std::greater<int> > q;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int64_t sum(int64_t m,int64_t g){
  return m+(m/g-1)*(m/g)/2*g+(m/g)*(m%g);
}

int main(){
  int M,A,B;
  scanf("%d %d %d",&M,&A,&B);
  q.push(0);
  int high=0;
  while(!q.empty()){
    int x=q.top();
    q.pop();
    if(x<0||x>400000||vis[x]) continue;
    vis[x]=true;
    high=std::max(high,x);
    fs[high]++;
    q.push(x+A);
    q.push(x-B);
  }
  for(int i=1;i<=400000;i++){
    fs[i]+=fs[i-1];
  }
  for(int i=1;i<=400000;i++){
    fs[i]+=fs[i-1];
  }
  if(M<=400000){
    printf("%I64d\n",fs[M]);
    return 0;
  }else{
    int g=gcd(A,B);
    printf("%I64d\n",fs[400000]+sum(M+1,g)-sum(400000+1,g));
  }
  
  return 0;
}