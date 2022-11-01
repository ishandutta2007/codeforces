#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX =300000+10;
int InDeg[MAX];
int Count;
int Ans[MAX];
int n,m;
/*
Note that a topological sort is not unique, and there can be several topological sorts for a graph.
*/

void TopoSort(vector<int> v[])
{
    priority_queue<int, vector<int>, greater<int> > PQ;
    for(int i=1; i<=n; i++) //0
        if(InDeg[i]==0) PQ.push(i);

    while(!PQ.empty()) //BFS
    {
        int Tmp = PQ.top();
        PQ.pop();
        Ans[Count++] = Tmp;
        for(int i=0; i<v[Tmp].size(); i++)
        {
            InDeg[v[Tmp][i]]--;
            if(InDeg[v[Tmp][i]]==0) PQ.push(v[Tmp][i]);
        }
    }
}
vector<int> V[MAX];
int b[MAX];
int a[MAX][26];
int ans = 1;
void dfs(int u)
{
  if(a[u][b[u]]) return;
  a[u][b[u]] = 1;
  for(int v:V[u])
  {
    dfs(v);
    for(int i=0;i<=25;i++) {
      a[u][i] = max(a[u][i],a[v][i] + (b[u]==i));
      ans = max(ans,a[u][i]);
    }
  }
}
int main(int argc, char const *argv[]) {



  Count = 0;
  std::cin >> n >> m;
  string s;
  std::cin >> s;
  for(int i=1;i<=n;i++) {
    b[i] = s[i-1]-'a';
  }
  int x,y;
  memset(InDeg, 0, sizeof(InDeg));
  for(int i=0; i<m; i++)
  {
      cin>>x>>y;
      InDeg[y]++;
      V[x].push_back(y);
  }
  TopoSort(V);
  if(Count!=n) {
    std::cout << "-1" << '\n';
    exit(0);
  }
  for(int i=1;i<=n;i++) {
    dfs(i);
  }
  std::cout << ans << '\n';
  return 0;
}