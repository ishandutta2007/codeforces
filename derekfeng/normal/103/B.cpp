#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool u[103],w[103];
vector <int> g[103],circle,cur;
int dfsc(int i){
  if (u[i]) return 0;
  u[i]=1;
  int ans=1;
  for (int j=0;j<g[i].size();j++) ans+=dfsc(g[i][j]);
  return ans;
}
int dfs(int v,int pr=-1){
  cur.push_back(v);
  u[v]=true;
  for (int i=0;i<g[v].size();i++){
    if (g[v][i]==pr) continue;
    if (u[g[v][i]]){
      while (cur.back()!=g[v][i]){
        circle.push_back(cur.back());
        cur.pop_back();
      }
      circle.push_back(cur.back());
      return 1;
    }
    if (dfs(g[v][i],v)) return 1;
  }
  cur.pop_back();
  return 0;
}
bool dfs2(int v,int pr=-1){
  if (u[v]) return 1;
  u[v]=1;
  for (int i=0;i<g[v].size();i++){
    if (g[v][i]==pr) continue;
    if (!w[v] && w[g[v][i]]) return 0;
    if (w[g[v][i]]) continue;
    if (u[g[v][i]]) return 0;
    if (!dfs2(g[v][i],v)) return 0;
  }
  return 1;
}
int main(){
  cin>>n>>m;
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (dfsc(0)!=n){cout<<"NO";return 0;}
  memset (u,0,sizeof(u));
  if (!dfs(0)){cout<<"NO";return 0;}
  memset (u,0,sizeof(u));
  for (int i=0;i<circle.size();i++){
    w[circle[i]]=1;
  }
  for (int i=0;i<circle.size();i++){
    if (!dfs2(circle[i])){cout<<"NO";return 0;}
  }
  cout<<"FHTAGN!";
  return 0;
}