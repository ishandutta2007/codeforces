//https://codeforces.com/problemset/problem/1257/D
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main(){
  int q; cin >> q;
  while(q--){
    int n; cin >> n;
    int monster[n];
    for(int i = 0; i<n; i++) cin >> monster[i];
    int m; cin >> m;
    int hero[n];
    fill(hero, hero+n, 0);
    for(int i = 0; i<m; i++){
      int a, b; cin >> a >> b;
      --b;
      hero[b] = max(hero[b], a);
    }
    int log[n+1];
    log[1] = 0;
    for (int i = 2; i <= n; i++) log[i] = log[i/2] + 1;

    int st[n][26];

    for (int i = 0; i < n; i++)
      st[i][0] = hero[i];

    for (int j = 1; j <= 25; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    
    int cur = 0;
    int maa = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
      maa = max(maa, monster[i]);
      cur++;
      int j = log[n-cur+1];
      int ma = max(st[cur-1][j], st[n - (1 << j)][j]);
      if(cur == 1) ans++;
      if(ma < maa){
        if(cur == 1){
          ans = -1;
          break;
        }
        cur = 0;
        maa = 0;
        i--;
      }
    }
    cout << ans << endl;
  }
}