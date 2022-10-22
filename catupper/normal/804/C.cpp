#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<int> edge[324000];
set<int> ok;
vector<int> ice[324000];
int n, m;
int col[324000];
int u, v, s[324000], c;

void dfs(int x, int last = -1){
  for(int i = 0;i < ice[x].size();i++){
    int c = ice[x][i];
    if(col[c]){
      ok.erase(col[c]);
    }
  }
  for(int i = 0;i < ice[x].size();i++){
    int c = ice[x][i];
    if(col[c])continue;
    col[c] = *ok.begin();
    ok.erase(col[c]);
  }
  for(int i = 0;i < ice[x].size();i++){
    int c = ice[x][i];
    ok.insert(col[c]);
  }
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    if(to == last)continue;
    dfs(to, x);
  }
}

int main(){
  scanf("%d%d", &n, &m);
  int ans = 0;
  for(int i = 1;i <= n;i++){
    scanf("%d", &s[i]);
    ans = max(ans, s[i]);
    for(int j = 0;j < s[i];j++){
      scanf("%d", &c);
      ice[i].push_back(c);
    }
  }
  for(int i = 0;i < n-1;i++){
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  for(int i = 1;i <= ans;i++)ok.insert(i);
  dfs(1);
  printf("%d\n", max(1, ans));
  for(int i = 1;i <= m;i++){
    printf("%d ",max(1, col[i]));
  }printf("\n");
  return 0;
}