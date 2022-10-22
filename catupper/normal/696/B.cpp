
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

double ans[108000];
int s[108000];
vector<int> edge[108000];
int n, p;
void dfs(int x){
  s[x] = 1;
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    dfs(to);
    s[x] += s[to];
  }
}

void dfs2(int x){
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    ans[to] = ans[x] + (s[x] - 1 - s[to]) * 0.5 + 1;
    dfs2(to);
  }
}

int main(){
  cin >> n;
  for(int i = 2;i <= n;i++){
    cin >> p;
    edge[p].push_back(i);
  }
  dfs(1);
  ans[1] = 1;
  dfs2(1);
  for(int i = 1;i <= n;i++){
    printf("%.10lf ", ans[i]);
  }
  cout << endl;
  return 0;
}