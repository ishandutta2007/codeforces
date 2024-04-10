#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<int> first,second;

int main(){
  int A,B;
  scanf("%d %d",&A,&B);
  int i=1;
  for(;A>=i;i++){
    first.push_back(i);
    A-=i;
  }
  if(A){
    int x=i-A;
    first.erase(std::find(first.begin(),first.end(),x));
    first.push_back(i++);
    if(x<=B){
      second.push_back(x);
      B-=x;
    }
  }
  for(;B>=i;i++){
    second.push_back(i);
    B-=i;
  }
  printf("%d\n",(int)first.size());
  for(int i=0;i<first.size();i++){
    if(i) printf(" ");
    printf("%d",first[i]);
  }
  printf("\n");
  printf("%d\n",(int)second.size());
  for(int i=0;i<second.size();i++){
    if(i) printf(" ");
    printf("%d",second[i]);
  }
  printf("\n");
  return 0;
}