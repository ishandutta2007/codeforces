#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 18;
int n;
bool know[N][N];
ll sol[1 << N];
ll pr[1 << N];
int coef[1 << N];

vector<int> curru;
vector<vector<int>> all;
ll cntpathfi[1 << N][N];
ll cntpath[1 << N];
int cb[1 << N];

void ru(int rem, int last) {
  if (rem == 0) {
    all.push_back(curru);
  }
  for (int i = last; i <= rem; i++) {
    curru.push_back(i);
    ru(rem - i, i);
    curru.pop_back();
  }
}

void fft(vector<ll>& a, int lim, bool inv) {
  if (!inv) {
    for (int l = 2; l <= lim; l *= 2) {
      for (int i = 0; i < lim; i += l) {
        for (int j = 0; j < l / 2; j++) {
          ll x = a[i + j], y = a[i + j + l / 2];
          a[i + j] = x;
          a[i + j + l / 2] = y + x;

        }
      }
    }
  }
  else {
    for (int l = 2; l <= lim; l *= 2) {
      for (int i = 0; i < lim; i += l) {
        for (int j = 0; j < l / 2; j++) {
          ll x = a[i + j], y = a[i + j + l / 2];
          a[i + j] = x;
          a[i + j + l / 2] = y - x;

        }
      }
    }
  }

}

vector<ll> vl[N + 1], ways;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  {
    coef[0] = 1;
    cb[0] = 0;
    for (int m = 1; m < (1 << N); m++) {
      for (int i = 0; i < N; i++) {
        if (m & (1 << i)) {
          coef[m] = -1 * coef[m ^ (1 << i)];
          cb[m] = 1 + cb[m ^ (1 << i)];
        }
      }
    }
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        know[i][j] = 1;
      }
    }
  }
  ru(n, 1);

  for (int i = 0; i < n; i++) {
    cntpathfi[1 << i][i] = 1;
  }

  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            continue;
          }
          if ((mask & (1 << j)) && know[i][j]) {
            cntpathfi[mask][i] += (cntpathfi[mask ^ (1 << i)][j]);
          }
        }
      }
    }
  }

  cntpath[0] = 1;
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        cntpath[mask] += cntpathfi[mask][i];
      }
    }
  }



  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (int)all[i].size();
    ///cout<<i << " : " << (int)all[i].size()<<", "<<sum<<"\n";
  }
  ///exit(0);

  map<vector<int>, ll> cnt;
  {
    for (int j = 0; j <= N; j++) {
      vl[j].resize(1 << n, 0);
      for (int i = 0; i < (1 << n); i++) {
        if (cb[i] == j) {
          vl[j][i] = cntpath[i];
        }
      }
      fft(vl[j], 1 << n, 0);
    }
    ways.resize(1 << n);
    for (auto& v : all) {
      for (int i = 0; i < (1 << n); i++) {
        ways[i] = 1;
      }
      for (auto& l : v) {
        for (int i = 0; i < (1 << n); i++) {
          ways[i] *= vl[l][i];
        }
      }
      fft(ways, 1 << n, 1);
      cnt[v] = ways[(1 << n) - 1];
    }
  }


  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    int low = 0;
    vector<int> le;
    int zu = 0;
    while (low < n) {
      int high = low;
      while (high < n - 1 && (mask & (1 << high))) {
        high++;
      }
      zu += high - low + 1;
      le.push_back(high - low + 1);
      low = high + 1;
    }
    sort(le.begin(), le.end());
    sol[mask] = cnt[le];
  }

  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    pr[mask] = coef[mask] * sol[mask];
  }
  for (int bit = 0; bit < n - 1; bit++) {
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
      if ((mask & (1 << bit))) {
        pr[mask ^ (1 << bit)] += pr[mask];
      }
    }
  }


  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    cout << abs(pr[mask]) << " ";
  }
  cout << "\n";

}