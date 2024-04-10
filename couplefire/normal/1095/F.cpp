#include <bits/stdc++.h>
using namespace std;
#define N 200001
long long parent[N];
long long ssize[N];
multimap<long long, long long> ma;
multimap<long long, pair<long long, long long>> mma;

long long find_set(long long v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void make_set(long long v) {
  parent[v] = v;
  ssize[v] = 1;
}

void union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ssize[a] < ssize[b])
      swap(a, b);
    parent[b] = a;
    ssize[a] += ssize[b];
  }
}

int main() {
  long long n, m;
  cin >> n >> m;
  for(long long i = 0; i<n; i++){
    long long a;
    cin >> a;
    make_set(i);
    ma.insert(make_pair(a, i));
  }
  for(long long i = 0; i<m; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    mma.insert(make_pair(c, make_pair(a, b)));
  }
  long long total = 0;
  while(true){
    while(!mma.empty() && find_set(mma.begin()->second.first) == find_set(mma.begin()->second.second)){
      mma.erase(mma.begin());
    }
    while((++ma.begin()) != ma.end() && find_set(ma.begin()->second) == find_set((++ma.begin())->second)){
      ma.erase((++ma.begin()));
    }
    if(ma.size() == 1) break; 
    if(!mma.empty() && mma.begin()->first < ma.begin()->first + (++ma.begin())->first){
      union_sets(mma.begin()->second.first, mma.begin()->second.second);
      total += mma.begin()->first;
    }
    else{
      union_sets(ma.begin()->second, (++ma.begin())->second);
      total += ma.begin()->first + (++ma.begin())->first;
    }
  }
  cout << total << endl;
}