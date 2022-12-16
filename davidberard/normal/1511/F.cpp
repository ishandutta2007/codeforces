#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

vector<vector<ll>> mats[30];

vector<vector<ll>> mult(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
  vector<vector<ll>> ans(A.size(), vector<ll>(B[0].size(), 0));
  for (int i=0; i<A.size(); ++i) {
    for (int j=0; j<B[0].size(); ++j) {
      for (int k=0; k<B.size(); ++k) {
        ans[i][j] += A[i][k] * B[k][j]%MOD;
      }
      ans[i][j] %= MOD;
    }
  }
  return ans;
}

int idr(char c) {
  return c-'a';
}

struct TN {
  char val;
  int idx;
  int prev;
  int dep = -1;
  bool is_term;
  int nxt[26];
};

TN t[100];
int zz = 0;
int yy = 0;

void add_string(string s) {
  int idx = 0;
  int q = 0;
  for (auto& c : s) {
    if (!t[idx].nxt[idr(c)]) {
      t[idx].nxt[idr(c)] = ++zz;
    }
    int nv = t[idx].nxt[idr(c)];
    t[nv].prev = idx;
    idx = t[idx].nxt[idr(c)];
    t[idx].dep = q++;
    t[idx].val = c;
  }
  t[idx].is_term = true;
}

void get_avail(vector<int>& res, int idx) {
  for (int i=0; i<26; ++i) {
    if (t[idx].nxt[i]) {
      res.push_back(t[idx].nxt[i]);
    }
    if (t[idx].is_term && t[0].nxt[i]) {
      res.push_back(t[0].nxt[i]);
    }
  }
}

int state[100][100];
bool term[10000];

int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(state, -1, sizeof state);
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    string s;
    cin >> s;
    add_string(s);
  }

  for (int i=0; i<=zz; ++i) {
    for (int j=0; j<=zz; ++j) {
      int a = i, b = j;
      if (t[a].dep < t[b].dep) {
        swap(a, b);
      }
      if (((!i) ^ (!j)) != 0) {
        continue;
      }

      bool good = true;
      if (t[a].val != t[b].val) {
        good = false;
      }
      /*
      while (good && t[b].dep >= 0) {
        if (t[a].val != t[b].val) {
          good = false;
        }
        a = t[a].prev;
        b = t[b].prev;
      }
      */

      if (good) {
        term[yy] = t[i].is_term && t[j].is_term;
        state[i][j] = yy++;
      }
    }
  }

  vector<int> ai, aj;
  mats[0] = vector<vector<ll>>(yy, vector<ll>(yy, 0));
  for (int i=0; i<=zz; ++i) {
    for (int j=0; j<=zz; ++j) {
      if (state[i][j] == -1) {
        continue;
      }
      ai.clear();
      aj.clear();
      get_avail(ai, i);
      get_avail(aj, j);
      for (auto& x : ai) {
        for (auto& y : aj) {
          if (state[x][y] == -1) {
            continue;
          }
          //cerr << "( " << i << "," << j << ") -> (" << x << "," << y << ")" << endl;
          mats[0][state[i][j]][state[x][y]] = 1;
        }
      }
    }
  }

  for (int i=0; i<29; ++i) {
    mats[i+1] = mult(mats[i], mats[i]);
  }
  for (int i=0; i<yy; ++i) {
    for (int j=0; j<yy; ++j) {
      //cerr << mats[12][i][j] << " ";
    }
    //cerr << endl;
  }
  vector<vector<ll>> init(1, vector<ll>(yy, 0));
  init[0][0] = 1;
  auto res = init;
  for (int p=0; m; m/=2, p++) {
    if (m&1) {
      //cerr << "." <<p << "\n";
      res = mult(res, mats[p]);
    }
  }
  ll ans = 0;
  for (int i=0; i<yy; ++i) {
    if (term[i]) {
      //cerr << " term : " << i << endl;
      ans += res[0][i];
    }
  }
  cout << ans%MOD << "\n";

  return 0;
}