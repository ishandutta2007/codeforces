#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ns;
vector<pair<int,pair<int,int>>> queries;
bool sorted[300000],inversion[300000];
int main() {
  int n,m,t,l,r;
  scanf ("%d %d",&n,&m);
  vector<int> arr(n);
  for (auto &a : arr) a = 1e9;
  while (m--) {
    scanf ("%d %d %d",&t,&l,&r);
    queries.push_back({t,{l,r}});
    if (t == 0) ns.push_back({l-1,r-1});
    else for (int i = l; i < r; i++) sorted[i] = 1;
  }  
  sort(ns.begin(),ns.end());
  for (auto p : ns) {
    bool found = false, f1 = false;
    for (int i = p.first+1; i <= p.second; i++) if (inversion[i]) f1 = 1;
    if (f1) continue;
    for (int i = p.first+1; i <= p.second; i++) 
      if (!sorted[i]) {inversion[i] = 1; arr[i] = arr[i-1]-1; found = 1; break;}
    if (!found) return !printf ("NO\n");
  }
  if (0) for (auto p : queries) {
    bool found = false;
    for (int i = p.second.first; i < p.second.second; i++) {
      if (p.first && arr[i] < arr[i-1]) return !printf ("NO\n");
      else if (!p.first && arr[i] < arr[i-1]) found = 1;
    }
    if (!p.first && !found) return !printf ("NO\n");
  }
  printf ("YES\n");
  for (int i = 0; i < n; i++) printf ("%d%c",arr[i],i==n-1?'\n':' ');
  return 0;
}