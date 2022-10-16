#include <iostream>

int memo[200][200];

int dfs_solve(int a1,int a2){
  if(a1==0||a2==0) return 0;
  if(memo[a1][a2]>0) return memo[a1][a2];
  if(a1>1) memo[a1][a2]=std::max(memo[a1][a2],1+dfs_solve(a1-2,a2+1));
  if(a2>1) memo[a1][a2]=std::max(memo[a1][a2],1+dfs_solve(a1+1,a2-2));
  return memo[a1][a2];
}

int main(){
  int A1,A2;
  std::cin>>A1>>A2;
  std::cout<<dfs_solve(A1,A2)<<std::endl;
  return 0;
}