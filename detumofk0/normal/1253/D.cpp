#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int res;
int lab[N];

int find(int x) {
  return lab[x] < 0 ? x : lab[x] = find(lab[x]);
}

void join(int x, int y) {
  x = find(x); y = find(y);
  if(x == y) return;
  if(x < y) swap(x, y);
  res--;
  lab[y] = x;
}

int n, m;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  memset(lab, -1, sizeof lab);

  cin >> n >> m;
  res = n;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    join(u, v);
  }


  int comp = 1, lar = find(1);
  for(int i = 2; i <= n; ++i){
    if(i > lar) ++comp;
    lar = max(lar, find(i));
  }

  cout << res - comp << endl;

  return 0;
}