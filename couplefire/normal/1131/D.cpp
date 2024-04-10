#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005

int parent[MAXN];
int siz[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int dp[MAXN] = {0};
int n, m; 

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
  parent[v] = v;
  siz[v] = 1;
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b])
      swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
  }
}

bool isCyclicUtil(int v, bool visit[], bool *recStack) 
{ 
    if(visit[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visit[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        vector<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visit[*i] && isCyclicUtil(*i, visit, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visit = new bool[n+m]; 
    bool *recStack = new bool[n+m]; 
    for(int i = 0; i < n+m; i++) 
    { 
        visit[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < n+m; i++) 
        if (isCyclicUtil(i, visit, recStack)) 
            return true; 
  
    return false; 
} 

void dfs(int v){
  if(visited[v]) return;
  visited[v] = 1;
  for(auto u : adj[v]){
    dfs(u);
    dp[v] = max(dp[v], dp[u]+1);
  }
}

int main() {
  //freopen("a.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i<MAXN; i++) make_set(i);
  char grid[n][m];
  for(int i = 0; i<n; i++){
    string s; cin >> s;
    for(int j = 0; j<m; j++){
      if(s[j] == '=') union_sets(i, j+n);
      grid[i][j] = s[j];
    }
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(grid[i][j] == '=') continue;
      else if(grid[i][j] == '<')adj[find_set(j+n)].push_back(find_set(i));
      else adj[find_set(i)].push_back(find_set(j+n));
    }
  }
  if(isCyclic()){
    cout << "NO" << endl;
    exit(0);
  }
  for(int i = 0; i<n+m; i++){
    if(!visited[i]) dfs(i);
  }
  cout << "YES" << endl;
  for(int i = 0; i<n; i++){
    cout << dp[find_set(i)]+1 << " ";
  }
  cout << endl;
  for(int i = n; i<n+m; i++){
    cout << dp[find_set(i)]+1 << " ";
  }
}