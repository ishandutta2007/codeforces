#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int inc;

struct cosa {
  int val;
  cosa* f[5];
  cosa() {
    val = inc++;
    for (int i = 0; i < 5; ++i) f[i] = nullptr;
  }
};

const int N = 6000000;
int V[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  inc = 0;
  cosa* root = new cosa();
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    cosa* p = root;
    for (auto c : a) {
      int t = c - 'a';
      if (p->f[t] == nullptr) {
        p->f[t] = new cosa();
      }
      p = p->f[t];
    }
    ++V[p->val];
  }
  for (int i = 0; i < m; ++i) {
    string a;
    cin >> a;
    int conta = 0;
    for (auto c : a) if (c == '?') ++conta;
    int val = 1;
    for (int j = 0; j < conta; ++j) val *= 6;
    set<int> S;
    for (int mask = 0; mask < val; ++mask) {
      int m = mask;
      cosa* p = root;
      bool pot = true;
      for (auto c : a) {
        int t = c - 'a';
        if (c == '?') {
          t = m%6;
          m /= 6;
          if (t == 5) continue;
        }
        if (p->f[t] == nullptr) {
          pot = false;
          break;
        }
        p = p->f[t];
      }
      if (pot) S.insert(p->val);
    }
    int res = 0;
    for (auto x : S) res += V[x];
    cout << res << '\n';
  }
}