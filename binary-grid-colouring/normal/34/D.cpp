#include<bits/stdc++.h>

using namespace std;

int n;
int r1,r2;
vector<int>edge[50010];
int ans[50010];

void dfs(int x,int fa)
{
  ans[x] = fa;
  for (size_t i = 0; i < (int)edge[x].size(); i++) {
    if(edge[x][i]==fa)continue;
    dfs(edge[x][i],x);
  }
}
int main(int argc, char const *argv[]) {
  std::cin >> n >> r1 >> r2;
  for (size_t i = 1; i <= n; i++) {
    if(i!=r1)
    {
      int a;
      std::cin >> a;
      edge[a].push_back(i);
      edge[i].push_back(a);
    }
  }
  dfs(r2,-1);
  for (size_t i = 1; i <= n; i++) {
    /* code */
    if(i!=r2){
      std::cout << ans[i] << " ";
    }
  }
  std::cout << '\n';
  return 0;
}