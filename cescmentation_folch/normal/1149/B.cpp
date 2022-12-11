#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<vi> vvi;

const int N = 100010;
int S[26][N + 10];
const int M = 260;
int R[M][M][M];

int main() {
  for (int i = 0; i < 26; ++i) S[i][N] = N;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a = 0;
  int b = 0;
  int c = 0;
  string vala, valb, valc;
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int K[26];
  for (int i = 0; i < 26; ++i) K[i] = N;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      S[j][i] = K[j];
    }
    if (i == 0) break;
    int d = s[i-1]-'a';
    K[d] = i;
  }
  while (q--) {
    char mander;
    int val;
    char ext;
    cin >> mander >> val;
    if (mander == '-') {
      if (val == 1) {
        vala.pop_back();
        --a;
      }
      else if (val == 2) {
        valb.pop_back();
        --b;
      }
      else {
        valc.pop_back();
        --c;
      }
    } else {
      cin >> ext;
      if (val == 1) {
        vala.push_back(ext);
        ++a;
        for (int i = 0; i <= c; ++i) {
          for (int j = 0; j <= b; ++j) {
            R[i][j][a] = S[ext-'a'][R[i][j][a-1]];
            if (i) R[i][j][a] = min(R[i][j][a], S[valc[i-1]-'a'][R[i-1][j][a]]);
            if (j) R[i][j][a] = min(R[i][j][a], S[valb[j-1]-'a'][R[i][j-1][a]]);
          }
        }
      }
      else if (val == 2) {
        ++b;
        valb.push_back(ext);
        for (int i = 0; i <= c; ++i) {
          for (int j = 0; j <= a; ++j) {
            R[i][b][j] = S[ext-'a'][R[i][b-1][j]];
            if (i) R[i][b][j] = min(R[i][b][j], S[valc[i-1]-'a'][R[i-1][b][j]]);
            if (j) R[i][b][j] = min(R[i][b][j], S[vala[j-1]-'a'][R[i][b][j-1]]);
          }
        }
      }
      else {
        ++c;
        valc.push_back(ext);
        for (int i = 0; i <= b; ++i) {
          for (int j = 0; j <= a; ++j) {
            R[c][i][j] = S[ext-'a'][R[c-1][i][j]];
            if (i) R[c][i][j] = min(R[c][i][j], S[valb[i-1]-'a'][R[c][i-1][j]]);
            if (j) R[c][i][j] = min(R[c][i][j], S[vala[j-1]-'a'][R[c][i][j-1]]);
          }
        }
      }
    }
    if (R[c][b][a] <= n) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}