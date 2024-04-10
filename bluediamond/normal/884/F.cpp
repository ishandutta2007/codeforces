#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n;
string s;
int a[N];
int c[N];
int f[26];
int sol;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - 'a';
    cin >> c[i];
    sol += c[i];
  }
  for (int i = 1; i <= n / 2; i++) {
    if (a[i] == a[n + 1 - i]) {
      f[a[i]]++;
      sol -= min(c[i], c[n + 1 - i]);
    }
  }
  int coco = (int) 1e9;
  for (int x = 0; x < 26; x++) {
    int len = 0;
    for (int y = 0; y < 26; y++) {
      if (x != y) {
        len += f[y];
      }
    }
    int cntx = 0;
    while (cntx + 1 <= f[x] && cntx + 1 <= len) {
      cntx++;
    }
    vector<int> cnt(26, 0);
    int total = 0, mf = 0;
    for (int y = 0; y < 26; y++) {
      if (x == y) {
        cnt[y] = cntx;
      } else {
        cnt[y] = f[y];
      }
      total += cnt[y];
      mf = max(mf, cnt[y]);
    }
    if (2 * mf <= total) {
      int rem = f[x] - cntx;
      if (rem == 0) {
        coco = 0;
        break;
      }
      vector<int> av;
      for (int i = 1; i <= n / 2; i++) {
        if (a[i] != a[n + 1 - i] && a[i] != x && a[n + 1 - i] != x) {
          av.push_back(min(c[i], c[n + 1 - i]));
        }
      }
      if (rem <= (int) av.size()) {
        sort(av.begin(), av.end());
        int now = 0;
        for (int i = 0; i < rem; i++) {
          now += av[i];
        }
        coco = min(coco, now);
      }
    }
  }
  sol -= coco;
  cout << sol << "\n";
}