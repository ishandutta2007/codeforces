#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

std::vector<int> xs;
int N;
int A,B;

bool test(int limit){
  std::set<int> set;
  set.insert(A);
  set.insert(B);
  for(int x:xs){
    while(set.size()&&*set.begin()<x-limit){
      set.erase(set.begin());
    }
    while(set.size()&&*set.rbegin()>x+limit){
      set.erase(*set.rbegin());
    }
    if(set.empty()){
      return false;
    }
    set.insert(x);
  }
  return true;
}

int main(){
  scanf("%d %d %d",&N,&A,&B);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    xs.push_back(X);
  }
  int low=std::abs(A-B)-1,high=1e9;
  while(high-low>1){
    int mid=(low+high)/2;
    if(test(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%d\n",high);
  return 0;
}