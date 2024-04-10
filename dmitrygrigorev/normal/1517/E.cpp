#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

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

int ans;
const int INF = 1e9;

vector<ll> suff;
vector<ll> s_suff;
vector<ll> p_suff;

int n;

void recursion(vector<int> &v, int index, int s, int p, int last_s, int last_p, ll delta) {

  if (index == v.size()) {
    if (delta > 0) {
     add(ans, 1);
    }
    return;
  }

  if (p == 1 && last_s < 1e6) {
    if (last_s == index - 1) {
      delta -= suff[n - index];
      //cout << delta << endl;
      if (s <= 1 && delta > 0) add(ans, 1);
      return;
    }
    else {
      //cout << index << " " << delta << endl;
      delta += suff[n - index];
      if (p >= 1 && delta > 0) add(ans, 1);

      delta -= 2LL*v.back();
      if (n-1-last_s >= s && delta > 0) add(ans, 1);
      return;
    }
  }

  if (p == 2 && s == 2 && last_p == index - 1) {
    int max_take = (n - index + 1) / 2;

   // cout << max_take << " " << index << " " << n << endl;

    int L = -1, R = max_take + 1;
    while (R - L > 1) {
      ll D;
      int M = (L+R)/2;
      if (M == 0) {
        D = delta + suff[n-index];
      }
      else {
        D = delta + (s_suff[n - index] - p_suff[n-index-2*M+1]) + suff[n-index-2*M+1];
      }
      //cout << M << " " << D << endl;
      if (D > 0) L = M;
      else R = M;
    }

    //cout << delta << endl;

    add(ans, L+1);

//////////////////////////////////////////////////////////
    if (n - index >= 2) {
      max_take = (n - index) / 2 - 1;


      //cout << max_take << " " << index << " " << n << endl;

      L = -1, R = max_take + 1;
      while (R - L > 1) {
        ll D;
        int M = (L+R)/2;
        if (M == 0) {
          D = delta + suff[n-index] - 2LL*v.back();
        }
        else {
          D = delta + (s_suff[n - index] - p_suff[n-index-2*M+1]) + suff[n-index-2*M+1] - 2LL*v.back();
        }
        //cout << M << " " << D << endl;
        if (D > 0) L = M;
        else R = M;
      }

      //cout << delta << endl;

      add(ans, L+1);

    }

    return;
  }

  if (index - last_s >= s) {
    recursion(v, index + 1, index - last_s, p, index, last_p, delta - v[index]);
  }

  if (index - last_p <= p) {
    recursion(v, index + 1, s, index - last_p, last_s, index, delta + v[index]);
  }



}

void solve() {
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  suff.clear();
  p_suff.clear();
  s_suff.clear();

  ans = 0;
  suff.pb(0);
  s_suff.pb(0);
  p_suff.pb(0);

  for (int i = 0; i < n; ++i) {
    suff.pb(suff.back() + v[n - i - 1]);
    ll Z = s_suff.back();
    s_suff.pb(p_suff.back() - v[n - i - 1]);
    p_suff.pb(Z + v[n - i - 1]);
  }

  recursion(v, 0, -INF, INF, 1e7, -1e7, 0);
  cout << ans << '\n';

}



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}