#include <bits/stdc++.h>
using namespace std;
#define N 2001
#define MOD 1000000007
int n, m, k;
bool visited[N] = {0};
int num = 0;

bool reachable(int a, int b){
  int mi = min(a, b);
  int ma = max(a, b);
  return (abs(k-abs(b-a))) % 2 && (ma-mi+1) <= k&& (min(mi, n-1-ma)*2+ma-mi+1)>=k;
}

void dfsUtil(int v){
  visited[v] = true;
  for(int i = 0; i<n; i++){
    if(!visited[i] && reachable(v, i)) dfsUtil(i);
  }
}

void dfs(){
  for(int i = 0; i<n; i++){
    if(!visited[i]){
      num++;
      dfsUtil(i);
    }
  }
}

int main() {
  cin >> n >> m >> k; 
  dfs();
  long long p = 1;
  for(int i = 0; i<num; i++){
    p *= m;
    p  = (p%MOD+MOD)%MOD;
  }
  cout << p << endl;
}