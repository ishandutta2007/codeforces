#include <bits/stdc++.h>
using namespace std;
#define N 200001

long long n;
vector<long long> adj[N];
long long plea[N];
long long subMax[N] = {0};
long long subSum[N];
long long ans = LONG_MIN;
bool work = false;

void findS(long long v, long long p){
  subSum[v] = plea[v];
  for(int i = 0; i<adj[v].size(); i++){
    if(adj[v][i] == p) continue;
    findS(adj[v][i], v);
    subSum[v] += subSum[adj[v][i]];
  }
}

void findM(long long v, long long p){
  subMax[v] = subSum[v];
  for(long long i = 0; i<adj[v].size(); i++){
    if(adj[v][i] == p) continue;
    findM(adj[v][i], v);
    subMax[v] = max(subMax[adj[v][i]], subMax[v]);
  }
}

void dfs(long long v, long long p){
  long long m1 = LONG_MIN, m2=LONG_MIN;
  for(long long i = 0; i<adj[v].size(); i++){
    if(adj[v][i] == p) continue;
    if(subMax[adj[v][i]] > m1){
      m2 = m1;
      m1 = subMax[adj[v][i]];
    }
    else if(subMax[adj[v][i]] > m2) m2 = subMax[adj[v][i]];
    dfs(adj[v][i], v);
  }
  if(adj[v].size() >= 3 || (adj[v].size() == 2 && p == -1)){
    ans = max(ans, m1+m2);
    work = true;
  }
}

int main() {
  scanf("%lld", &n);
  for(long long i = 0; i<n; i++){
    long long a;
    scanf("%lld", &a);
    plea[i] = a;
  }
  for(long long i = 0; i<n-1; i++){
    long long a, b;
    scanf("%lld %lld", &a, &b);
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  findS(0, -1);
  findM(0, -1);
  dfs(0, -1);
  //for(int i = 0; i<n; i++) cout << subMax[i] << endl; 
  if(!work) cout << "Impossible" << endl;
  else cout << ans << endl;
}