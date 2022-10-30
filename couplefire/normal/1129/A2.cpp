#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int siz[n];
  int mi[n];
  fill(siz, siz+n, 0);
  fill(mi, mi+n, INT_MAX);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    siz[a]++;
    mi[a] = min(mi[a], (b>=a) ? b-a : n+b-a);
  }
  for(int i = 0; i<n; i++){
    int ma = INT_MIN;
    for(int j = 0; j<n; j++){
      int k = j;
      if(k < i) k+=n;
      if(siz[j] == 0) continue;
      ma = max(ma, k-i+(siz[j]-1)*n+mi[j]);
    }
    printf("%d ", ma);
  }
  cout << endl;
}