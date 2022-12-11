#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

const int M = 2400;
const int N = 210;
const int C = 11;

bool T[N][C][M];
string P[N][2];

void anal(string a, int pp) {
  for (int b = 1; b <= C; ++b) {
    for (int i = 0; i < (1<<b); ++i) {
      for (int j = 0; j < (int)a.size() - b + 1; ++j) {
        if (T[pp][b - 1][i]) break;
        int k = i;
        for (int tt = 1; tt <= b; ++tt) {
          if (k%2 != (int)(a[j + tt - 1] - '0')) break;
          k /= 2;
          if (tt == b) T[pp][b - 1][i] = 1;
        }
      }
    }
  }
}

void cop(int a, int b, int c) {
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < M; ++j) {
      T[c][i][j] = (T[a][i][j] or T[b][i][j]);
    }
  }
}

string conc(string a, string b) {
  for (int i = 0; i < (int)b.size(); ++i)
    a.push_back(b[i]);
  return a;
}

void creat(int a, int b, int nou) {
  cop(a, b, nou);
  anal(conc(P[a][1], P[b][0]), nou);
  P[nou][0] = P[a][0];
  int j = 0;
  while (P[nou][0].size() < C and j < P[b][0].size()) {
    P[nou][0].push_back(P[b][0][j]);
    ++j;
  }
  j = 0;
  string aux;
  while ((int)P[b][1].size() + j < C and j < P[a][1].size()) {
    aux.push_back(P[a][1][(int)P[a][1].size() - j - 1]);
    ++j;
  }
  for (int i = j - 1; i >= 0; --i) P[nou][1].push_back(aux[i]);
  for (int i = 0; i < P[b][1].size(); ++i) P[nou][1].push_back(P[b][1][i]);
}

int res(int x) {
  int ans = 0;
  for (int b = 0; b < C; ++b) {
    bool tt = true;
    for (int i = 0; i < (1<<(b + 1)); ++i) {
      if (!T[x][b][i]) {
        tt = false;
        break;
      }
    }
    if (tt) ans = b + 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    anal(a, i);
    for (int j = 0; j < (int)a.size() and j < C; ++j) P[i][0].push_back(a[j]);
    for (int j = max(0, (int)a.size() - C); j < (int)a.size(); ++j) P[i][1].push_back(a[j]);
  }
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    creat(a, b, n);
    cout << res(n) << '\n';
    ++n;
  }
}