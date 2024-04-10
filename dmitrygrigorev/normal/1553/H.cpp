#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

vector<int> ans;
const int N = (1<<19);

vector<int> arr[N];

struct Vertex {
  int ed[2];
};

vector<Vertex> bor;
void create() {
  Vertex q;
  q.ed[0] = -1;
  q.ed[1] = -1;
  bor.pb(q);
}

int add(int x, int y) {

  if (bor[x].ed[y] == -1) {
    create();
    bor[x].ed[y] = bor.size() - 1;
  }
  return bor[x].ed[y];

}

int get_min(int st, int rem, int bits) {

  int ans = st * (1<<(bits - 1));
  int cur = bor[0].ed[st];

  for (int i = bits - 2; i >= 0; --i) {
    int Q = (((1<<i)&rem) > 0);
    if (bor[cur].ed[Q] != -1) {
      ans += (1<<i) * Q;
      cur = bor[cur].ed[Q];
    }
    else {
      ans += (1<<i) * (1 - Q);
      cur = bor[cur].ed[(1 - Q)];
    }
  }

  return ans;
}

int get_max(int st, int rem, int bits) {

  int ans = st * (1<<(bits - 1));
  int cur = bor[0].ed[st];

  for (int i = bits - 2; i >= 0; --i) {
    int Q = 1 - (((1<<i)&rem) > 0);
    if (bor[cur].ed[Q] != -1) {
      ans += (1<<i) * Q;
      cur = bor[cur].ed[Q];
    }
    else {
      ans += (1<<i) * (1 - Q);
      cur = bor[cur].ed[(1 - Q)];
    }
  }

  return ans;
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  ans.assign((1<<k), 1e9);
  for (int bits = 0; bits < k; ++bits) {
    for (int i = 0; i < (1<<k); ++i) arr[i].clear();
    for (int i = 0; i < n; ++i) {
      int left_part = v[i] >> (k - bits);
      int right_part = v[i] ^ (left_part << (k - bits));
      arr[left_part].pb(right_part);
    }

    vector<int> best_remainder(1<<(k-bits), 1e9);

    for (int i = 0; i < (1<<k); ++i) {
      if (arr[i].size() != 0) {
        
        bor.clear();
        create();
        for (auto x : arr[i]) {
          int cur = 0;
          for (int j = k - bits - 1; j >= 0; --j) {
            if ((x & (1<<j)) != 0) {
              cur = add(cur, 1);
            }
            else cur = add(cur, 0);
          }
        }

        if (bor[0].ed[0] == -1 || bor[0].ed[1] == -1) continue;

        for (int rem = 0; rem < (1<<(k - bits)); ++rem) {
          if (rem < (1<<(k - bits - 1))) {
            int A = get_min(1, rem, k - bits);
            int B = get_max(0, rem, k - bits);
            //cout << rem << " " << A << " " << B << endl;
            best_remainder[rem] = min(best_remainder[rem], abs((A^rem) - (B^rem)));
          }
          else {
            int A = get_min(0, rem, k - bits);
            int B = get_max(1, rem, k - bits);
            best_remainder[rem] = min(best_remainder[rem], abs((A^rem) - (B^rem)));
          }
        }

      }
    }

    for (int i = 0; i < (1<<k); ++i) {
      ans[i] = min(ans[i], best_remainder[i % (1<<(k - bits))]);
    }

  }

  for (auto x : ans) cout << x << " ";

}