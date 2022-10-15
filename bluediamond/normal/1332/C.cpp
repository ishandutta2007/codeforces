#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int k;
int t[N];
string s;

int get(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = get(t[a]);
  }
}

void unite(int a, int b) {
  t[get(a)] = get(b);
}

int tot[N];
int fr[N][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
      t[i] = i;
      tot[i] = 0;
      for (int j = 0; j < 26; j++) {
        fr[i][j] = 0;
      }
    }
    for (int i = 1; i < n + 1 - i; i++) {
      unite(i, n + 1 - i);
    }
    for (int i = 1; i + k <= n; i++) {
      unite(i, i + k);
    }
    for (int i = 1; i <= n; i++) {
      tot[get(i)]++;
      fr[get(i)][s[i - 1] - 'a']++;
    }
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (tot[i]) {
        int mx = 0;
        for (int j = 0; j < 26; j++) {
          mx = max(mx, fr[i][j]);
        }
        sol += tot[i] - mx;
      }
    }
    cout << sol << "\n";
  }


}