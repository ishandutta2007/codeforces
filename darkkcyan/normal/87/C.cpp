#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
int gru[maxn];
int xg[maxn];
vector<int> kl[maxn];
bool mark[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) {
    for (auto u: kl[i]) {
      int s = (i * 2 / u + 1 - u) / 2;
      int e = s + u - 1;
      int x = xg[e] ^ xg[s - 1];
      mark[x] = 1;
    }

    gru[i] = 0;
    while (gru[i] < maxn and mark[gru[i]]) ++ gru[i];
    xg[i] = xg[i - 1] ^ gru[i];
    for (auto u: kl[i]) {
      int s = (i * 2 / u + 1 - u) / 2;
      int e = s + u - 1;
      int x = xg[e] ^ xg[s - 1];
      mark[x] = 0;
    }
    int sum = i + i - 1;
    for (int f = 2; sum <= n and i - f >= 0; ++f) {
      // clog << sum << endl;
      kl[sum].push_back(f);
      sum += i - f;
    }
  }
  
  if (gru[n] == 0) {
    cout << -1;
    return 0;
  }
  sort(kl[n].begin(), kl[n].end());
  for (auto u: kl[n]) {
    int s = (n * 2 / u + 1 - u) / 2;
    int e = s + u - 1;
    int x = xg[e] ^ xg[s - 1];
    if (x == 0) {
      cout << u;
      return 0;
    }
  }
  
  return 0;
}