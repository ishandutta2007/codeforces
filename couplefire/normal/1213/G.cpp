#include <bits/stdc++.h>
using namespace std;
#define N 200001
long long n, m;
long long parent[N];
long long siz[N];
multimap<long long, pair<long long, long long>> mp;
long long arr[N] = {0};
long long ans = 0;

long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void make_set(long long v) {
  parent[v] = v;
  siz[v] = 1;
}

void union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b]) swap(a, b);
    ans -= siz[a]*(siz[a]-1)/2;
    ans -= siz[b]*(siz[b]-1)/2;
    parent[b] = a;
    siz[a] += siz[b];
    ans += siz[a]*(siz[a]-1)/2;
  }
}

int main() {
  cin >> n >> m;
  for(long long i = 0; i<n-1; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    --a;--b;
    mp.insert(make_pair(c, make_pair(a, b)));
  }
  for(long long i = 0; i<n; i++) make_set(i);
  for(auto i : mp){
    long long a = i.second.first, b = i.second.second, c = i.first;
    union_sets(a, b);
    arr[c] = ans;
  }
  for(long long i = 1; i<N; i++){
    if(arr[i] == 0) arr[i] = arr[i-1];
  }
  for(long long i = 0; i<m; i++){
    long long a;
    cin >> a;
    cout << arr[a] << " ";
  }
  cout << endl;
}