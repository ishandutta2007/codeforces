#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int mask_list[15][1<<14];
int mask_cnt[15];
int mask_ord[1<<14];
int adj[15][15];


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=0; i<n; ++i) {
    string s;
    cin >> s;
    for (int j=0; j<n; ++j) {
      adj[i][j] = s[j]-'0';
    }
  }

  for (int i=0; i<(1<<n); ++i) {
    int x = __builtin_popcount(i);
    mask_ord[i] = mask_cnt[x];
    mask_list[x][mask_cnt[x]++] = i;
  }

  auto pre = vector<vector<array<ll, 14>>>(1, vector<array<ll, 14>>(n, array<ll, 14>()));
  for (int i=0; i<n; ++i) {
    pre[0][i][i] = 1;
  }

  for (int i=2; i<=n; ++i) {
    auto nxt = vector<vector<array<ll, 14>>>(1<<(i-1), vector<array<ll, 14>>(mask_cnt[i], array<ll, 14>()));

    for (int j=0; j<(1<<(i-2)); ++j) {
      for (int k=0; k<mask_cnt[i-1]; ++k) {
        for (int lst=0; lst<n; ++lst) {
          int x = mask_list[i-1][k];
          for (int z=0; z<n; ++z) {
            if (!((x>>z)&1)) {
              int y = x^(1<<z);
              int q = (j<<1)+adj[z][lst];
              nxt[q][mask_ord[y]][z] += pre[j][k][lst];
            }
          }
        }
      }
    }
    pre.clear();
    swap(nxt, pre);
  }

  for (int i=0; i<(1<<(n-1)); ++i) {
    ll t = 0;
    for (int x=0; x<n; ++x) {
      t += pre[i][0][x];
    }
    cout << t << " ";
  }

  cout << endl;

  return 0;
}